<p style="font-size:30px;color:hsl(204, 90%, 45%)"><b>fileToStr</b></p>

----
Reads a file as a string 

### Description
This opcode will read a file and write it to a string output.  

### Syntax
```csound
SOut fileToStr SFilename
```

### Initialization

* **SOut** -- string output
* **SFilename** -- filename, if no path is given it will write file to current directory 


### Performance

> This opcode works at i-time only. 

### Example
This example shows strToFile writing the a string to a file called string.txt

```csound
<CsoundSynthesizer>
<CsOptions>
; Select audio/midi flags here according to platform
-odac --opcode-lib=../build/libstrToArray.so 
;-iadc    ;;;uncomment -iadc if RT audio input is needed too
; For Non-realtime ouput leave only the line below:
; -o diskin.wav -W ;;; for file output any platform
</CsOptions>
<CsInstruments>
0dbfs=1

instr 1
    SString = "strRemove.csd"
    SOutput fileToStr SString
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
Success, file was written
```

### Credits
Author: Rory Walsh
2018
