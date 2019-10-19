## Various Csound plugin opcodes

Binaries are available [here](https://dev.azure.com/rorywalsh/csoundPluginOpcodes)

Just go to Pipelines->Builds, click the latest build and then click the Artifacts link on the top right to download. To use the opcodes, add the plugin to to your CsOptions sections. For example:

```
<CsOptions>
-n -d -+rtmidi=NULL -M0 --midi-key-cps=4 --midi-velocity-amp=5 --opcode-lib=channelStateOpcodes.dll
</CsOptions>
```