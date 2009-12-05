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

/**
@file ToneGenerator.hh
@brief Plays a tone through the main soundcard using GStreamer.
*/

#ifndef JAF__TONE_GENERATOR_HH
#define JAF__TONE_GENERATOR_HH

#include <iostream>
#include <gst/gst.h>

/**
@class ToneGenerator
@brief Plays a tone through the main soundcard using GStreamer.
*/
class ToneGenerator {
	GstElement *m_audio_pipe;
	GstElement *m_tone_src;
	GstElement *m_audio_sink;

public:
	/** */
	ToneGenerator ();

	/** */
	~ToneGenerator ();

	/**
	@brief Play a tone.
	@param freq Frequency of the tone.
	@param duration Length of time in milliseconds to play the tone.
	*/
	void play (float freq, size_t duration);

	/** Stop the underlying system. */
	void stop ();
};

#endif //JAF__TONE_GENERATOR_HH

