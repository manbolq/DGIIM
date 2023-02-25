<Qucs Schematic 0.0.19>
<Properties>
  <View=0,-49,1382,855,1,0,60>
  <Grid=10,10,1>
  <DataSet=Ejercicio 4.dat>
  <DataDisplay=Ejercicio 4.dpl>
  <OpenDisplay=1>
  <Script=Ejercicio 4.m>
  <RunScript=0>
  <showFrame=0>
  <FrameText0=Título>
  <FrameText1=Dibujado por:>
  <FrameText2=Fecha:>
  <FrameText3=Revisión:>
</Properties>
<Symbol>
</Symbol>
<Components>
  <Vac V1 1 360 360 18 -26 0 1 "10 V" 1 "1 GHz" 0 "0" 0 "0" 0>
  <R R1 1 970 270 -26 15 0 0 "82 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <VProbe Vi 1 140 280 28 -31 0 0>
  <VProbe Voc 1 520 100 28 -31 0 0>
  <Eqn Eqn1 1 750 10 -39 18 0 0 "Tdb_c=20*log10(abs(Voc.v)/abs(Vi.v))" 1 "yes" 0>
  <Eqn Eqn2 1 1120 10 -39 18 0 0 "argT_c=arg(Voc.v) - arg(Vi.v)" 1 "yes" 0>
  <.AC AC1 1 160 -20 0 47 0 0 "log" 1 "0.01 Hz" 1 "1 MHz" 1 "19" 1 "no" 0>
  <C C1 1 540 270 -26 17 0 0 "970 nF" 1 "0" 0 "neutral" 0>
  <L L1 1 740 270 -26 10 0 0 "26.1 mH" 1 "" 0>
</Components>
<Wires>
  <360 390 360 410 "" 0 0 0 "">
  <360 430 1100 430 "" 0 0 0 "">
  <1100 270 1100 430 "" 0 0 0 "">
  <1000 270 1100 270 "" 0 0 0 "">
  <770 270 940 270 "" 0 0 0 "">
  <570 270 590 270 "" 0 0 0 "">
  <360 270 440 270 "" 0 0 0 "">
  <360 270 360 300 "" 0 0 0 "">
  <360 300 360 330 "" 0 0 0 "">
  <150 300 360 300 "" 0 0 0 "">
  <130 300 130 410 "" 0 0 0 "">
  <360 410 360 430 "" 0 0 0 "">
  <130 410 360 410 "" 0 0 0 "">
  <440 270 510 270 "" 0 0 0 "">
  <590 270 710 270 "" 0 0 0 "">
  <590 120 590 270 "" 0 0 0 "">
  <530 120 590 120 "" 0 0 0 "">
  <440 120 440 270 "" 0 0 0 "">
  <440 120 510 120 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 230 735 351 245 3 #c0c0c0 1 10 1 0.01 1 1e+06 1 -6.59679 1 -2.82749 1 -1 0.5 1 315 0 225 "f (Hz)" "arg(Tc) (rad)" "">
	<"argT_c" #0000ff 0 3 0 0 0>
  </Rect>
  <Rect 730 736 373 245 3 #c0c0c0 1 10 1 0.01 1 1e+06 1 -132.503 50 17.5885 1 -1 0.5 1 315 0 225 "f (Hz)" "20*log|Tc|" "">
	<"Tdb_c" #0000ff 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
</Paintings>
