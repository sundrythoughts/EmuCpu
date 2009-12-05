/*
 * sim8086 -- Emulates an Intel 8086 processor
 * Copyright (C) 2009  Joseph Freeman (jfree143dev AT gmail DOT com)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "ToneGenerator.hh"

ToneGenerator::ToneGenerator () {
	m_audio_pipe = gst_pipeline_new ("audio-pip");
	m_tone_src = gst_element_factory_make ("audiotestsrc", "tone-src");
	m_audio_sink = gst_element_factory_make ("autoaudiosink", "audio-sink");
	gst_bin_add_many (GST_BIN(m_audio_pipe), m_tone_src, m_audio_sink, NULL);
	gst_element_link_many (m_tone_src, m_audio_sink, NULL);
	g_object_set (G_OBJECT(m_tone_src),
	              "freq", 0.0,
	              NULL);
	gst_element_set_state (m_audio_pipe, GST_STATE_PLAYING);
}

ToneGenerator::~ToneGenerator () {
	stop ();
	gst_object_unref (GST_OBJECT (m_audio_pipe));
}

void
ToneGenerator::play (float freq, size_t duration) {
	g_object_set (G_OBJECT(m_tone_src), "freq", freq, NULL);
	g_usleep (duration * 1000);
	g_object_set (G_OBJECT(m_tone_src), "freq", 0.0, NULL);
}

void
ToneGenerator::stop () {
	gst_element_set_state (m_audio_pipe, GST_STATE_NULL);
}

