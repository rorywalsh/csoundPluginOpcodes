<p style="font-size:50px;text-align: center;color:hsl(204, 90%, 45%)"><b>Csound plugin opcodes</b></p>

This repository hosts a collection of, relatively untested, opcodes for the Csound audio framework. 

If you wish to try them out you with your installed version of Csound you can do so by downloading the current release for your platforms through the link below.  

<br>

<a href="https://github.com/rorywalsh/csoundPluginOpcodes/releases/download/1.0/Linux.zip"><img src="imgs/Linux.png" style="width:20%;" hspace="30"/></a><a href="https://github.com/rorywalsh/csoundPluginOpcodes/releases/download/1.0/Win64.zip><img src="imgs/Windows.png" style="width:20%;" hspace="30"/></a><a href="https://github.com/rorywalsh/csoundPluginOpcodes/releases/download/1.0/MacOS.zip"><img src="imgs/Apple.png" style="width:20%;" hspace="30"/></a>

<br>


To use any of the plugin opcodes you will should place them into your pluin64 directory. Alternatively, you can tell Csound where they are located. To do this, you can add a `--plugin-lib` flag to your `CsOptions`. For example:

```csound
<CsOptions>
--opcode-lib=channelStateOpcodes.dll
</CsOptions>
```

## Contributing

This repository has a [CI build](https://dev.azure.com/rorywalsh/csoundPluginOpcodes/_build) that is triggered to compile all the opcodes on Linux, MacOS and Windows. If you have some opcodes that you would like to contribute to this collection, even if it just to avail of the automated build system, fork the repo, write your opcode and make a pull request. All of the plugin here use the [Csound Opcode-SDK](https://github.com/csound/opcode_sdk). Note that camelCase is used to name each plugin. This is done to help differentiate them from internal Csound plugins.  