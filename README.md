# Harjarobotti

## Software
### Tavoitteet
- Harjauskone liikkuu tilassa väistellen esteitä edessä olevien kolmen ultraäänianturin avulla
- Liikkuminen tapahtuu kahden moottorin avulla, jotka pyörittävät renkaita molempiin suuntiin
- Harjojen pyörityksen moottori käynnistyy ja sammuu omasta napista (mobiili vai fyysinen)
- Kone löytää oman latauspisteensä tilassa (ei ajankohtainen)
- Arduinon käyttö tapahtuisi mobiililaitteen avulla (TOIVE) -> pohja mobiiliohjelmoinnin projektista, jossa applikaatio ottaa yhteyden arduinoon. 
- ```Toimeksiantaja toivoi Arduinoa, tosin myöskään Rasberry Pi ei ole täysin poiskaan suljettu.```

### Liitynnät
- 3 kpl HC-SR04 ultraäänisensori (Echo ja Trikkaus)
- 3 kpl akkuja (Jännite/kapasiteetti 12V/1,3Ah)
- L298 H-silta moottoriohjainkortti (2A) Linkin takaa löytyvä [esteitä väistelevä "auto"](https://www.youtube.com/watch?v=1n_KjpMfVT0&t=178s&ab_channel=DIYBuilder) on erittäin hyvä pienempi malli harjauskonerobotista. Laitteessa käytetään L293d H-siltaa. 
- IRFZ24 N-channel mosfet harjoille

- 3 kpl moottori (Jännite 12V, 900 rpm)
- 2 kpl Arduino UNO

### Extra
- Powerled
- Akunmonitorointi

