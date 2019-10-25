<CsoundSynthesizer>
<CsOptions>
-odac --opcode-lib=../build/Debug/fileToStr.dll
</CsOptions>
<CsInstruments>
0dbfs=1

instr 1
iCnt = 0
SString = "strRemove.csd"
SOutput fileToStr SString
prints SOutput
prints "\n"
endin

</CsInstruments>
<CsScore>
i1 0 z
</CsScore>
</CsoundSynthesizer>