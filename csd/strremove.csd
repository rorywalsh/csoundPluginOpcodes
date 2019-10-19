<CsoundSynthesizer>
<CsOptions>
-n --opcode-lib=../build/libstrremove.dylib
</CsOptions>
<CsInstruments>
0dbfs=1

instr 1
iCnt = 0
SString = "Hello there my name is"
SOutput strremove SString, "Hello"
prints SOutput
prints "\n"
endin

</CsInstruments>
<CsScore>
i1 0 1
</CsScore>
</CsoundSynthesizer>