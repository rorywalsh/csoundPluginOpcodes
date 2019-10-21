<CsoundSynthesizer>
<CsOptions>
-n --opcode-lib=../build/libstrRemove.dylib
</CsOptions>
<CsInstruments>
0dbfs=1

instr 1
iCnt = 0
SString = "Hello there, my name is Rory"
SOutput strRemove SString, "Hello there, "
prints SOutput
endin

</CsInstruments>
<CsScore>
i1 0 1
</CsScore>
</CsoundSynthesizer>