<Qucs Schematic 0.0.19>
<Properties>
  <View=0,0,1320,800,1,0,0>
  <Grid=10,10,1>
  <DataSet=Ejercicio 4_Vth.dat>
  <DataDisplay=Ejercicio 4_Vth.dpl>
  <OpenDisplay=1>
  <Script=Ejercicio 4_Vth.m>
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
  <R R2 1 800 220 -26 15 0 0 "2 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <R R3 1 800 510 -26 15 0 0 "3 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <R R5 1 1080 510 -26 15 0 0 "5 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <R R4 1 1080 220 -26 15 0 0 "4 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <.DC DC1 1 150 120 0 47 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <R R1 1 490 370 -26 15 0 0 "1 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <Idc I1 1 400 510 18 -26 0 1 "1 mA" 1>
  <GND * 1 690 670 0 0 0 0>
  <VProbe Vth1 1 480 160 -58 -31 1 2>
  <Vdc V1 1 950 380 18 -26 0 1 "5 V" 1>
</Components>
<Wires>
  <670 220 670 370 "" 0 0 0 "">
  <670 220 770 220 "" 0 0 0 "">
  <670 510 770 510 "" 0 0 0 "">
  <1110 510 1200 510 "" 0 0 0 "">
  <830 510 950 510 "" 0 0 0 "">
  <1200 220 1200 510 "" 0 0 0 "">
  <1110 220 1200 220 "" 0 0 0 "">
  <830 220 950 220 "" 0 0 0 "">
  <1200 510 1200 670 "" 0 0 0 "">
  <400 540 400 670 "" 0 0 0 "">
  <950 220 1050 220 "" 0 0 0 "">
  <950 510 1050 510 "" 0 0 0 "">
  <950 220 950 350 "" 0 0 0 "">
  <160 760 1280 760 "" 0 0 0 "">
  <1280 510 1280 760 "" 0 0 0 "">
  <1200 510 1280 510 "" 0 0 0 "">
  <400 370 400 480 "" 0 0 0 "">
  <400 370 460 370 "" 0 0 0 "">
  <400 670 690 670 "" 0 0 0 "">
  <690 670 1200 670 "" 0 0 0 "">
  <470 180 470 240 "" 0 0 0 "">
  <160 240 470 240 "" 0 0 0 "">
  <160 240 160 760 "" 0 0 0 "">
  <490 180 620 180 "" 0 0 0 "">
  <670 370 670 510 "" 0 0 0 "">
  <520 370 620 370 "" 0 0 0 "">
  <620 370 670 370 "" 0 0 0 "">
  <620 180 620 370 "" 0 0 0 "">
  <950 410 950 510 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Tab 1050 110 228 63 3 #c0c0c0 1 00 1 0 1 1 1 0 1 1 1 0 1 1 315 0 225 "" "" "">
	<"Vth1.V" #0000ff 0 3 1 0 0>
  </Tab>
</Diagrams>
<Paintings>
</Paintings>
