<p style="font-size:30px;color:hsl(204, 90%, 45%)"><b>strRemove</b></p>

----
Removes all occurrences of a string from another. 

### Description
This opcode will search a string for another. Each time it finds the search string it will delete it. The opcode return a new string with all instances of the search string removed.   

### Syntax
```csound
SOutput strRemove SInput, SSearchString
```

### Initialization

* **SOutput** -- the input string minus all occurrences of the search string
* **SInput** -- string to search
* **SSearchString** -- the string that will be looked for 

### Performance

> This opcode works at i-time only. 

### Example
This example shows strRemove being used to remove the string 'Hello there, ' from the longer string 'Hello there, my name is Rory'. 

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

Output:

```
my name is Rory
```

### Credits
Author: Rory Walsh
2018
