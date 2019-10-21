<p style="font-size:30px;color:hsl(204, 90%, 45%)"><b>channelStateSave</b></p>

----

Saves all channel data to file 

### Description
This opcode will save the value of each channel declared in a Csound orchestra to a JSON file on disk. It can be used with the `channelStateRecall` opcode to create a robust preset system.    

### Syntax
```csound
iRes channelStateSave SFilename
```

### Initialization

* **iRes** -- 1 for success, 0 for fail
* **SFilename** -- filename


### Performance

> This opcode works at i-time only. 

### Example
This example shows channelStateSave being used to save the current states of a all Cabbage widgets to disk. The states can be recalled using the `channelStateRecall` opcode. 

```csound
<CsoundSynthesizer>
<CsOptions>
; Select audio/midi flags here according to platform
-odac --opcode-lib=../build/libstrRemove.dylib 
;-iadc    ;;;uncomment -iadc if RT audio input is needed too
; For Non-realtime ouput leave only the line below:
; -o diskin.wav -W ;;; for file output any platform
</CsOptions>
<CsInstruments>
0dbfs=1

instr 1
    SString = "Hello there, my name is Rory"
    SOutput strRemove SString, "Hello there, "
    prints SOutput
endin

</CsInstruments>
<CsScore>
i1 0 1
</CsScore>
</CsoundSynthesizer>
```

### Credits
Author: Rory Walsh
2019
