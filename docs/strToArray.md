<p style="font-size:30px;color:hsl(204, 90%, 45%)"><b>strToArray</b></p>

----
Converts a string to a string array.

### Description
This opcode will take a string as input and convert it to an array. Users can select the delimiter used to break the string up.     

### Syntax
```csound
SArray[] strToArray SInput, SDelimiter
```

### Initialization

* **SArray[]** -- a string array made up of tokens from the input string
* **SInput** -- string to convert to array
* **SDelimiter** -- delimiter that will be used to break up string into tokens 

### Performance

> This opcode works at i-time only. 

### Example
This example shows strToArray being used to convert a string into a string array. In this case whitespaces are used as deimiters. 

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
    iCnt init 0
    SString = "Hello there, my name is Rory"
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
```

Output:

```
Hello
there,
my
name
is
Rory
```

### Credits
Author: Rory Walsh
2018
