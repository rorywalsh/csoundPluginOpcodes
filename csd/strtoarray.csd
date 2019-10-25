<CsoundSynthesizer>
<CsOptions>
-n --opcode-lib=../build/libstrtoarray.dylib
</CsOptions>
<CsInstruments>
0dbfs=1

instr 1
iCnt = 0
SString = "Hello there my name is"
SArray[] strToArray SString, " "
while iCnt<lenarray(SArray) do
    prints SArray[iCnt]
    iCnt+=1
    prints "\n"
od
endin

</CsInstruments>
<CsScore>
i1 0 1
</CsScore>
</CsoundSynthesizer>