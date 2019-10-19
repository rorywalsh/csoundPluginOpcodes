<CsoundSynthesizer>
<CsOptions>
-n --opcode-lib=../build/libtrigexpseg.so
</CsOptions>
<CsInstruments>
0dbfs = 1
nchnls = 2
ksmps = 32

instr 1
kTrig init 1
aEnv expseg 0, 1, 1, 1, .001
a1 oscili aEnv, 400
outs a1, a1
;fout "testExpseg.wav", 4, a1
kTrig = 0
endin

instr 2
kTrig init 1
aEnv trigexpseg kTrig, 0, 1, 1, 1, .001
a1 oscili aEnv, 400
outs a1, a1
;fout "testTrigExp.wav", 4, a1
kTrig = 0
endin

</CsInstruments>
<CsScore>
i1 0 2
i2 0 2
</CsScore>
</CsoundSynthesizer>