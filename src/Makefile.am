bin_PROGRAMS = emucpu

emucpu_CPPFLAGS = -DQT_NO_DEBUG -DQT_NO_KEYWORDS

emucpu_SOURCES =  EmuCpu.cc \
                  ArithmeticLogicUnit.hh \
                  ArithmeticLogicUnit.cc \
                  BusInterfaceUnit.hh \
                  BusInterfaceUnit.cc \
                  Cpu.hh \
                  Cpu.cc \
                  CpuComponents.hh \
                  CpuComponents.cc \
                  Defines.hh \
                  Defines.cc \
                  DisassemblySignalsAndSlots.hh \
                  DisassemblySignalsAndSlots.cc \
                  DisassemblyWidget.hh \
                  DisassemblyWidget.cc \
                  ExecutionUnit.hh \
                  ExecutionUnit.cc \
                  FlagRegisterSignalsAndSlots.hh \
                  FlagRegisterSignalsAndSlots.cc \
                  FlagsWidget.hh \
                  FlagsWidget.cc \
                  GeneralRegisterSignalsAndSlots.hh \
                  GeneralRegisterSignalsAndSlots.cc \
                  GeneralRegistersWidget.hh \
                  GeneralRegistersWidget.cc \
                  Immediate.hh \
                  Instruction.hh \
                  Instruction.cc \
                  InstructionDecoder.hh \
                  InstructionDecoder.cc \
                  InstructionDisassembly.hh \
                  InstructionDisassembly.cc \
                  InstructionTable.hh \
                  InstructionTable.cc \
                  INumberReadableWritable.hh \
                  IOPorts.hh \
                  IOPorts.cc \
                  Loader.hh \
                  Loader.cc \
                  Memory.hh \
                  Memory.cc \
                  MemoryAddress.hh \
                  MemorySignalsAndSlots.hh \
                  MemorySignalsAndSlots.cc \
                  MemoryWidget.hh \
                  MemoryWidget.cc \
                  NumberWrapper.hh \
                  NumberWrapper.cc \
                  OperandList.hh \
                  OperandList.cc \
                  ProxyLayer.hh \
                  ProxyLayer.cc \
                  SegmentRegisterSignalsAndSlots.hh \
                  SegmentRegisterSignalsAndSlots.cc \
                  SegmentRegistersWidget.hh \
                  SegmentRegistersWidget.cc \
                  EmuCpuWindow.hh \
                  EmuCpuWindow.cc \
                  SoundSignalsAndSlots.hh \
                  SoundSignalsAndSlots.cc \
                  SoundWidget.hh \
                  SoundWidget.cc \
                  StackSignalsAndSlots.hh \
                  StackSignalsAndSlots.cc \
                  StackWidget.hh \
                  StackWidget.cc \
                  TerminalSignalsAndSlots.hh \
                  TerminalSignalsAndSlots.cc \
                  TerminalTextEdit.hh \
                  TerminalTextEdit.cc \
                  TerminalWidget.hh \
                  TerminalWidget.cc \
                  ToneGenerator.hh \
                  ToneGenerator.cc \
                  Types.hh \
                  Utility.hh \
                  Utility.cc

nodist_emucpu_SOURCES = moc_Cpu.cc \
                         moc_DisassemblySignalsAndSlots.cc \
                         moc_DisassemblyWidget.cc \
                         moc_FlagRegisterSignalsAndSlots.cc \
                         moc_FlagsWidget.cc \
                         moc_GeneralRegisterSignalsAndSlots.cc \
                         moc_GeneralRegistersWidget.cc \
                         moc_MemorySignalsAndSlots.cc \
                         moc_MemoryWidget.cc \
                         moc_ProxyLayer.cc \
                         moc_SegmentRegisterSignalsAndSlots.cc \
                         moc_SegmentRegistersWidget.cc \
                         moc_EmuCpuWindow.cc \
                         moc_SoundSignalsAndSlots.cc \
                         moc_SoundWidget.cc \
                         moc_StackSignalsAndSlots.cc \
                         moc_StackWidget.cc \
                         moc_TerminalSignalsAndSlots.cc \
                         moc_TerminalTextEdit.cc \
                         moc_TerminalWidget.cc

#Qt4 .ui files must be built BEFORE the emucpu program starts compiling
BUILT_SOURCES = ui_DisassemblyWidget.hh \
                ui_FlagsWidget.hh \
                ui_GeneralRegistersWidget.hh \
                ui_MemoryWidget.hh \
                ui_SegmentRegistersWidget.hh \
                ui_EmuCpuWindow.hh \
                ui_SoundWidget.hh \
                ui_StackWidget.hh \
                ui_TerminalWidget.hh

ui_%.hh: %.ui
	uic $< -o $@

moc_%.cc: %.hh
	moc $< -o $@

CLEANFILES = moc_*.cc \
             ui_*.hh

emucpu_LDADD = ${QT4_LIBS} ${SIGC2_LIBS} ${GST_LIBS}
emucpu_CXXFLAGS = ${QT4_CFLAGS} ${SIGC2_CFLAGS} ${GST_CFLAGS}
