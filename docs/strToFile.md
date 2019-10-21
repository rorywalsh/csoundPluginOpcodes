<p style="font-size:30px;color:hsl(204, 90%, 45%)"><b>strToFile</b></p>

----

Writes a string to disk 

### Description
This opcode will take a string input and write it to a user defined location on disk.  

### Syntax
```csound
iRes strToFile SInput, SFilename, iMode
```

### Initialization

* **iRes** -- 1 for success, 0 for fail
* **SInput** -- the input string minus all occurrences of the search string
* **SFilename** -- filename, if no path is given it will write file to current directory
* **iMode** -- 0 for overwrite (default), 1 for append  


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
    SString = "Hello there, my name is Rory"
    iRes strToFile SString, "string.txt"
    if iRes == 1 then
        prints "Success, file was written"
    else
        prints "Failed to write file"
    endif
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
