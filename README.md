# :hammer_and_wrench: Kompiliavimo instrukcijos

1. Atsisiųsti [MinGW make](https://sourceforge.net/projects/mingw/)
2. Klonuoti projekto direktoriją
3. Į komandinę eilutę įvesti komandą ```mingw32-make```
4. Aplanke, kuriame klonavote direktoriją, paleisti failą ***program.exe***

# :keyboard: Naudojimosi instrukcijos

Atsidarę programą turėsite 9 pasirinkimus:
1. Duomenų įvedimas ranka – turėsite vesti studentų vardus, pavardes, pažymius ir egzamino įvertinimą tiek kartų, kiek norėsite
2. Pažymiu generavimas – turėsite vesti tik studentų vardus ir pavardes, pažymiai kiekvienam studentui bus atsitiktinai sugeneruoti
3. Pažymiu ir vardų generavimas – visi duomenys apie studentus bus sugeneruoti (vardai ir pavardės atsitiktini iš fiksuoto sąrašo)
4. Skaityti duomenis iš failo – studentų konteineris užpildomas duomenimis iš norimo failo
5. Testuoti įvesties laiką – tikrinama, kiek užtrunka įvesti duomenis iš norimo failo
6. Kurti failą ir testuoti jo sukurimo laiką – galite pasirinkti, kokio dydžio studentų failą sugeneruosite
7. Skirstyti studentus iš failo į vargšiukus ir galvočius – iš anksčiau sugeneruotų failų vykdomas skirstymas pagal vidurkį ir jo metu testuojama įvesties trukmė, rikiavimas ir skirstymas
8. Testuoti Stud klasės metodus
9. Baigti darbą

# :notebook_with_decorative_cover: Klasės naudojimosi instrukcijos

### Įvesties operatorius

Galite ranka vesti studento vardą, pavardę ir tiek pažymių, kiek norite, tik reikia nurodyti įvedimo pabaigą įrašant pažymį -1. Tuomet reikia įvesti dar vieną skaičių - egzamino pažymį. Jeigu vedate iš failo, bus nuskaitomas vardas, pavardė ir pažymiai bei egzaminas be poreikio atskirti egzaminą nuo pažymių skaičiumi -1.

### Išvesties operatorius

Išvedamas studento vardas, pavardė ir galutiniai pažymiai pagal vidurkį bei medianą kiekvienam duomeniui suteikiant po 25 laukelius ir rikiuojant kairėje.

# :chart: Testavimas

Programa buvo ištestuota pagal tris strategijas ir su trimis konteineriais:
- Vector
- List
- Deque

>[!NOTE]
>Visų testų laikai pateikti iš 5 bandymų vidurkio.

### Rezultatai

Efektyviausia strategija buvo pirmoji, tikėtina dėl to, kad duomenų trinimas iš konteinerių užtrunka ilgai.

Visi konteineriai buvo maždaug vienodai efektyvūs.

### Sistemos specifikacijos: 
- CPU: AMD Ryzen 7 7840HS with Radeon 780M Graphics
- RAM: 32 GB 3200MHz LPDDR5
- SSD: SKHynix_HFS001TEJ9X115N 

### 1 strategija:

#### Vector testavimas

![image](https://github.com/user-attachments/assets/260c62a3-c532-44a8-9071-986b1255aa1d)
</br>

#### List testavimas

![image](https://github.com/user-attachments/assets/11715b4d-bd7f-4186-95b7-10fa77586269)
</br>

#### Deque testavimas

![image](https://github.com/user-attachments/assets/a2461b7f-4de6-4527-81d6-5e12dcf0c8c0)
</br></br>

### 2 strategija:

#### Vector testavimas

![image](https://github.com/user-attachments/assets/8c824515-7748-4838-85ea-2201df3a00fb)
</br>

#### List testavimas

![image](https://github.com/user-attachments/assets/6cf44ee7-a67d-4a0f-9357-9d34e80754df)
</br>

#### Deque testavimas

![image](https://github.com/user-attachments/assets/3be433a5-e6af-48bf-9ca4-7e445214f2c5)
</br>

### 3 strategija

#### Vector testavimas

![image](https://github.com/user-attachments/assets/b95058de-07c4-4ec8-bb96-9de3f103dadd)
</br>

#### List testavimas

![image](https://github.com/user-attachments/assets/bdaca316-f979-4962-9bbb-294131e28021)
</br>

#### Deque testavimas

![image](https://github.com/user-attachments/assets/7c077a3d-12de-4715-b0c4-2c38a9c675f2)

