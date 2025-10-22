# Operativni Sistemi - Pitanja i Odgovori

## 1. Osnovni Pojmovi

### 1. Koje poslove obavlja operativni sistem?
Operativni sistem obavlja sledeće poslove:
- Rukovanje procesorom (raspoređivanje procesa)
- Rukovanje radnom memorijom (alokacija i dealokacija)
- Rukovanje ulazno-izlaznim uređajima (kontrolerima)
- Rukovanje datotekama (organizacija i pristup)
- Rukovanje procesima (kreiranje, terminacija, sinhronizacija)
- Pružanje interfejsa prema korisniku i aplikacijama

### 2. Šta obuhvata pojam datoteke?
Datoteka obuhvata:
- Imenovanu kolekciju podataka na masovnoj memoriji
- Logičku celinu koja omogućava trajno čuvanje informacija
- Sadržaj (podatke) i metapodatke (atribute)
- Apstrakciju koja sakriva fizičke detalje skladištenja

### 3. Šta se nalazi u deskriptoru datoteke?
Deskriptor datoteke sadrži:
- Ime datoteke
- Tip datoteke
- Lokaciju datoteke na disku (poziciju prvog bloka ili tabelu blokova)
- Veličinu datoteke
- Prava pristupa (dozvole)
- Vremenske oznake (kreiranje, modifikacija, pristup)
- Vlasnika datoteke
- Pokazivač na sadržaj

### 4. Šta omogućuju datoteke?
Datoteke omogućuju:
- Trajno čuvanje podataka između izvršavanja programa
- Deljenje podataka između različitih programa i korisnika
- Organizaciju podataka u logičke celine
- Zaštitu podataka pomoću prava pristupa
- Prenos podataka između različitih sistema

### 5. Šta obavezno prethodi čitanju i pisanju datoteke?
Prethodi **otvaranje datoteke** (open operacija), kojom se:
- Proveravaju prava pristupa
- Učitava deskriptor datoteke u memoriju
- Inicijalizuje pokazivač pozicije u datoteci
- Vraća identifikator otvorene datoteke (file descriptor)

### 6. Šta sledi iza čitanja i pisanja datoteke?
Sledi **zatvaranje datoteke** (close operacija), kojom se:
- Oslobađaju sistemski resursi vezani za datoteku
- Ažuriraju metapodaci datoteke
- Prazne baferi (flush)
- Omogućava pristup drugim procesima

## 2. Procesi i Niti

### 7. Šta obuhvata pojam procesa?
Proces obuhvata:
- Program u izvršavanju
- Sliku procesa (kod, podaci, stek, hip)
- Deskriptor procesa sa svim atributima
- Resurse koje proces koristi
- Stanje izvršavanja (registri, programski brojač)

### 8. Šta se nalazi u deskriptoru procesa?
Deskriptor procesa (Process Control Block - PCB) sadrži:
- Identifikator procesa (PID)
- Stanje procesa (aktivan, spreman, blokiran)
- Programski brojač
- Vrednosti registara procesora
- Informacije o raspoređivanju (prioritet, kvantum)
- Informacije o memoriji (tabele stranica/segmenata)
- Informacije o ulazno-izlaznim operacijama
- Liste otvorenih datoteka
- Vlasnika procesa

### 9. Koja stanja procesa postoje?
Osnovna stanja procesa su:
- **Aktivan** (running) - proces se trenutno izvršava na procesoru
- **Spreman** (ready) - proces čeka na dodelu procesora
- **Blokiran** (blocked/waiting) - proces čeka na ulazno-izlaznu operaciju ili događaj

### 10. Kada je proces aktivan?
Proces je aktivan kada:
- Mu je dodeljen procesor
- Njegovi programski zahtevi se trenutno izvršavaju na procesoru
- Nalazi se u stanju izvršavanja (running state)

### 11. Šta je kvantum?
Kvantum je:
- Vremenski interval koji se dodeljuje procesu za izvršavanje
- Maksimalno vreme koje proces može kontinualno koristiti procesor
- Parametar raspoređivanja (obično 10-100ms)
- Nakon isteka kvantuma dolazi do preključivanja konteksta

### 12. Šta je sistemska nit?
Sistemska nit je:
- Nit koja se izvršava u kernelu operativnog sistema
- Nit koja ima privilegovani pristup hardveru
- Nit koja izvršava sistemske operacije
- Deo operativnog sistema koji radi u kernel režimu

### 13. Šta se dešava nakon isticanja kvantuma?
Nakon isticanja kvantuma:
- Dolazi do prekida tajmera
- Procesor se oduzima trenutno aktivnom procesu
- Proces prelazi iz aktivnog u spremno stanje
- Izvršava se raspoređivač koji bira novi proces
- Vrši se preključivanje konteksta

### 14. Po kom kriteriju se uvek bira aktivan proces?
Aktivan proces se bira po kriterijumu:
- **Prioriteta** - proces sa najvećim prioritetom dobija procesor
- Može se kombinovati sa drugim kriterijumima (vreme čekanja, tip procesa)
- Raspoređivač bira proces sa vrha reda spremnih procesa

### 15. Koji prelazi su mogući između stanja procesa?
Mogući prelazi:
- **Spreman → Aktivan**: dodela procesora (dispatch)
- **Aktivan → Spreman**: istek kvantuma ili prekid sa višim prioritetom
- **Aktivan → Blokiran**: čekanje na U/I operaciju ili događaj
- **Blokiran → Spreman**: završetak U/I operacije ili događaj se desio

### 16. Koji prelazi nisu mogući između stanja procesa?
Nemogući prelazi:
- **Spreman → Blokiran**: spremni proces ne može direktno u blokirano stanje
- **Blokiran → Aktivan**: blokirani proces mora prvo u spremno stanje

### 17. Šta omogućuju procesi?
Procesi omogućuju:
- Multiprogramiranje (više programa u memoriji istovremeno)
- Konkurentno izvršavanje programa
- Izolaciju i zaštitu između različitih programa
- Efikasno korišćenje resursa procesora
- Deljenje vremena procesora između više zadataka

### 18. Šta karakteriše sekvencijalni proces?
Sekvencijalni proces:
- Ima jednu nit izvršavanja
- Izvršava instrukcije redom, jednu po jednu
- Ne koristi paralelizam unutar procesa
- Jednostavan za razumevanje i debagovanje
- Ima jednu putanju izvršavanja

### 19. Šta karakteriše konkurentni proces?
Konkurentni proces:
- Ima više niti izvršavanja
- Niti se izvršavaju konkurentno (naizmenično ili paralelno)
- Deli resurse između svojih niti
- Zahteva sinhronizaciju između niti
- Omogućava bolje iskorišćenje resursa

### 20. Šta ima svaka nit konkurentnog procesa?
Svaka nit ima:
- **Sopstveni stek** za lokalne promenljive i pozive funkcija
- **Sopstveni programski brojač**
- **Sopstvene vrednosti registara**
- **Sopstveno stanje** (aktivna, spremna, blokirana)
- Deli sa drugim nitima: kod, podatke, heap, otvorene datoteke

### 21. Koje su razlike između procesa i niti?
Razlike:
- **Proces**: ima sopstveni adresni prostor, potpuna izolacija, težak za kreiranje
- **Nit**: deli adresni prostor sa procesom, manja izolacija, laka za kreiranje
- **Komunikacija**: između procesa teža (IPC), između niti lakša (deljene promenljive)
- **Overhead**: kreiranje procesa skupo, kreiranje niti jeftino
- **Zaštita**: procesi zaštićeni, niti u istom procesu mogu da se naruše

### 22. Koju operaciju uvodi modul za rukovanje procesorom?
Operacija: **Preključivanje konteksta** (context switch)
- Čuvanje stanja trenutnog procesa/niti
- Učitavanje stanja novog procesa/niti
- Promena aktivnog procesa na procesoru

### 23. Po čemu se razlikuju preključivanja između niti istog procesa i preključivanja između niti različitih procesa?
Razlike:
- **Isti proces**: ne menja se adresni prostor, brže preključivanje, samo se menjaju stek i registri
- **Različiti procesi**: menja se adresni prostor (TLB flush), sporije preključivanje, menjaju se i memorijske strukture

### 24. Koje operacije uvodi modul za rukovanje kontrolerima?
Operacije:
- **Iniciraj U/I operaciju** (start I/O)
- **Obradi prekid** (interrupt handler)
- **Čekaj na završetak** U/I operacije
- **DMA transfer**

### 25. Šta je cilj drajvera?
Cilj drajvera je:
- Apstrakcija hardvera za operativni sistem
- Sakrivanje detalja specifičnih za hardver
- Pružanje uniformnog interfejsa za pristup uređajima
- Upravljanje komunikacijom sa kontrolerom uređaja

### 26. Koje operacije uvodi modul za rukovanje radnom memorijom?
Operacije:
- **Alokacija memorije** (malloc/allocate)
- **Dealokacija memorije** (free/deallocate)
- **Translacija adresa** (logičke u fizičke)
- **Zaštita memorije**

### 27. Koje operacije poziva modul za rukovanje radnom memorijom kada podržava virtuelnu memoriju?
Operacije:
- **Stranični prekid** (page fault handler)
- **Učitavanje stranice** sa diska (page-in)
- **Izbacivanje stranice** na disk (page-out)
- **Zamena stranice** (page replacement)
- **Ažuriranje tabele stranica**

### 28. Koje operacije uvodi modul za rukovanje datotekama?
Operacije:
- **open** - otvaranje datoteke
- **close** - zatvaranje datoteke
- **read** - čitanje iz datoteke
- **write** - pisanje u datoteku
- **seek** - pozicioniranje u datoteci
- **create** - kreiranje datoteke
- **delete** - brisanje datoteke

### 29. Koje operacije poziva modul za rukovanje datotekama?
Poziva operacije:
- Modula za rukovanje diskom (blokovske operacije)
- Modula za rukovanje keš memorijom
- Modula za zaštitu (provera prava pristupa)

### 30. Šta omogućuju multiprocesing i multithreading?
Omogućuju:
- **Multiprocessing**: izvršavanje više procesa istovremeno na više procesora
- **Multithreading**: izvršavanje više niti istovremeno unutar procesa
- Povećanje propusnosti sistema
- Bolje iskorišćenje resursa
- Paralelno izvršavanje zadataka

### 31. Koje operacije uvodi modul za rukovanje procesima?
Operacije:
- **fork** - kreiranje procesa
- **exec** - zamena slike procesa
- **exit** - terminacija procesa
- **wait** - čekanje na završetak child procesa
- **kill** - slanje signala procesu

### 32. Koje operacije poziva modul za rukovanje procesima?
Poziva operacije:
- Modula za rukovanje memorijom (alokacija adresnog prostora)
- Modula za raspoređivanje (dodavanje u red spremnih)
- Modula za rukovanje datotekama (nasleđivanje otvorenih datoteka)

### 33. Koje module sadrži slojeviti operativni sistem?
Module:
1. **Hardware** (najniži sloj)
2. **Upravljanje procesorom i memorijom**
3. **Drajveri uređaja**
4. **Sistem datoteka**
5. **Upravljanje procesima**
6. **Sistemski pozivi**
7. **Interpreter komandnog jezika** (najviši sloj)

### 34. Šta omogućuju sistemski pozivi?
Sistemski pozivi omogućuju:
- Kontrolisan pristup hardveru iz korisničkog režima
- Izvršavanje privilegovanih operacija
- Interfejs između korisničkih programa i kernela
- Zaštitu sistema od neautorizovanog pristupa
- Apstrakciju hardvera za aplikacije

### 35. Koje adresne prostore podržava operativni sistem?
Adresni prostori:
- **Korisnički adresni prostor** (user space) - za aplikacije
- **Sistemski adresni prostor** (kernel space) - za kernel
- **Virtuelni adresni prostor** - logički prostor procesa
- **Fizički adresni prostor** - stvarna RAM memorija

### 36. Šta karakteriše interpreter komandnog jezika?
Karakteristike:
- Program koji prima i izvršava komande korisnika
- Interfejs između korisnika i operativnog sistema
- Može biti znakovni (CLI) ili grafički (GUI)
- Omogućava pokretanje programa, upravljanje datotekama, itd.
- Često podržava skriptovanje

### 37. Koji nivoi korišćenja operativnog sistema postoje?
Nivoi:
- **Nivo aplikacija** - korisničke aplikacije
- **Nivo sistemskih poziva** - programski interfejs
- **Nivo komandnog jezika** - shell/GUI
- **Nivo sistemskih programa** - utilities
- **Nivo kernela** - jezgro sistema

## 3. Konkurentnost i Sinhronizacija

### 38. Šta je preplitanje?
Preplitanje je:
- Izmenjivanje izvršavanja instrukcija više niti/procesa
- Nedeterministički redosled izvršavanja instrukcija
- Posledica konkurentnog izvršavanja
- Uzrok problema sinhronizacije

### 39. Da li preplitanje ima slučajan karakter?
Da, preplitanje ima **slučajan i nedeterministički** karakter:
- Zavisi od raspoređivanja operativnog sistema
- Zavisi od tajminga prekida
- Ne može se precizno predvideti
- Isti program može dati različite rezultate

### 40. Šta izaziva pojavu preplitanja?
Preplitanje izaziva:
- Konkurentno izvršavanje više niti/procesa
- Preključivanje konteksta od strane operativnog sistema
- Istovremeni pristup deljenim resursima
- Istek kvantuma
- Ulazno-izlazne operacije

### 41. Da li preplitanje može uticati na rezultat izvršavanja programa?
**Da**, preplitanje može uticati na rezultat kada:
- Postoje deljene promenljive bez adekvatne sinhronizacije
- Postoje race conditions
- Nema zaštite kritičnih sekcija
- Narušava se konzistentnost podataka

### 42. Šta su deljene promenljive?
Deljene promenljive su:
- Promenljive kojima pristupa više niti/procesa
- Nalaze se u deljenom memorijskom prostoru
- Zahtevaju sinhronizaciju za konzistentan pristup
- Potencijalni izvor race conditions

### 43. Šta je preduslov očuvanja konzistentnosti deljenih promenljivih?
Preduslov je:
- **Međusobna isključivost** (mutual exclusion)
- Samo jedna nit istovremeno pristupa deljenoj promenljivoj
- Korišćenje mehanizama sinhronizacije (mutex, semafori)
- Zaštita kritičnih sekcija

### 44. Šta su kritične sekcije?
Kritične sekcije su:
- Delovi koda koji pristupaju deljenim resursima
- Moraju se izvršavati atomski (bez prekida)
- Zahtevaju međusobnu isključivost
- Ne smeju se preplitati između više niti

### 45. Šta je sinhronizacija?
Sinhronizacija je:
- Koordinacija izvršavanja više niti/procesa
- Obezbeđivanje ispravnog redosleda pristupa resursima
- Sprečavanje race conditions
- Mehanizam za upravljanje konkurentnošću

### 46. Koje vrste sinhronizacije postoje?
Vrste:
- **Međusobna isključivost** (mutual exclusion) - zaštita kritičnih sekcija
- **Uslovljena sinhronizacija** (conditional synchronization) - čekanje na uslov
- **Sinhronizacija redosleda** - definisanje redosleda događaja

### 47. Šta je atomski region?
Atomski region je:
- Sekvenca instrukcija koja se izvršava nedeljivo
- Ili se izvrše sve instrukcije ili nijedna
- Ne može biti prekinuta tokom izvršavanja
- Obezbeđuje konzistentnost

### 48. Šta sužava primenu atomskih regiona?
Sužava:
- Složenost implementacije u hardveru
- Ograničenja u dužini atomske sekvence
- Performanse sistema (blokiranje drugih niti)
- Teško ih je realizovati u softveru

### 49. Čemu služi propusnica?
Propusnica (mutex) služi za:
- Obezbeđivanje međusobne isključivosti
- Zaštitu kritičnih sekcija
- Kontrolu pristupa deljenim resursima
- Sprečavanje simultanog pristupa

### 50. Šta se dešava sa niti koja zatraži, a ne dobije propusnicu?
Nit:
- Prelazi u **blokirano stanje**
- Čeka u redu čekanja na propusnicu
- Ne troši procesorsko vreme
- Biće aktivirana kada propusnica postane dostupna

### 51. Šta se dešava kada nit vrati propusnicu?
Kada nit vrati propusnicu:
- Propusnica postaje dostupna
- Jedna od čekajućih niti se budi
- Buđena nit zauzima propusnicu
- Buđena nit nastavlja izvršavanje

### 52. Kako se štiti konzistentnost propusnica?
Konzistentnost se štiti:
- Atomskim operacijama zauzimanja i oslobađanja
- Hardverskom podrškom (test-and-set, compare-and-swap)
- Onemogućavanjem prekida tokom operacija
- Korišćenjem spinlock-ova u kernelu

### 53. Šta je isključivi region?
Isključivi region je:
- Kritična sekcija zaštićena propusnicom
- Oblast koda gde samo jedna nit može biti
- Realizovan pomoću lock/unlock operacija
- Obezbeđuje međusobnu isključivost

### 54. Šta uvode poželjne osobine konkurentnih programa?
Uvode:
- **Napredak** (progress) - bar jedna nit napreduje
- **Pravičnost** (fairness) - sve niti dobijaju šansu
- **Odsustvo mrtve petlje** (deadlock freedom)
- **Odsustvo izgladnjivanja** (starvation freedom)

### 55. Po čemu se konkurentno programiranje razlikuje od sekvencijalnog?
Razlike:
- **Nedeterminizam** u konkurentnom
- **Potreba za sinhronizacijom** u konkurentnom
- **Složeniji debugging** u konkurentnom
- **Race conditions** samo u konkurentnom
- **Deadlock mogućnost** samo u konkurentnom

### 56. Koje prednosti ima konkurentna biblioteka u odnosu na konkurentni programski jezik?
Prednosti biblioteke:
- Ne zahteva novi kompilator
- Može se koristiti sa postojećim jezicima
- Fleksibilnija za ažuriranje
- Lakše proširiva
- Lakša za učenje

### 57. Kako se opisuju niti?
Niti se opisuju:
- **Funkcijom** koju nit izvršava
- **Parametrima** koji se prosleđuju niti
- **Atributima** niti (prioritet, stek veličina)
- Objektom niti (thread object)

### 58. Kako se kreiraju niti?
Niti se kreiraju:
- Pozivom funkcije za kreiranje (npr. `std::thread` u C++)
- Navođenjem funkcije koju nit izvršava
- Prosleđivanjem argumenata
- Automatski se startuje nakon kreiranja

### 59. Kada se zauzima propusnica deljene promenljive?
Zauzima se:
- **Pre pristupa** deljenoj promenljivoj
- Na početku kritične sekcije
- Pozivom `lock()` ili sličnom operacijom

### 60. Kada se oslobađa propusnica deljene promenljive?
Oslobađa se:
- **Posle pristupa** deljenoj promenljivoj
- Na kraju kritične sekcije
- Pozivom `unlock()` ili sličnom operacijom

### 61. Kakvu ulogu ima klasa mutex?
Klasa mutex:
- Implementira propusnicu/bravu
- Obezbeđuje međusobnu isključivost
- Ima operacije `lock()` i `unlock()`
- Štiti deljene resurse

### 62. Kakvu ulogu ima klasa unique_lock?
Klasa unique_lock:
- **RAII wrapper** za mutex
- Automatski zaključava mutex u konstruktoru
- Automatski otključava mutex u destruktoru
- Sprečava zaboravljanje otključavanja
- Može se koristiti sa condition_variable

### 63. Kakvu ulogu ima klasa condition_variable?
Klasa condition_variable:
- Omogućava **uslovljenu sinhronizaciju**
- Nit može čekati na ispunjenje uslova
- Nit može signalizirati druge niti (`notify_one`, `notify_all`)
- Koristi se uz mutex

### 64. Koje vrste razmene poruka postoje?
Vrste:
- **Sinhrona razmena** - pošiljalac čeka na primaoca
- **Asinhrona razmena** - pošiljalac ne čeka
- **Direktna komunikacija** - imenovanje procesa
- **Indirektna komunikacija** - preko mailbox-ova

### 65. U čemu se razlikuju sinhrona i asinhrona razmena poruka?
Razlike:
- **Sinhrona**: pošiljalac blokira dok primalac ne primi poruku (rendezvous)
- **Asinhrona**: pošiljalac odmah nastavlja, poruka ide u bafer
- **Sinhrona**: automatska sinhronizacija
- **Asinhrona**: potreban bafer, bez čekanja

### 66. Opisati problem pet filozofa
Problem:
- **5 filozofa** sedi za okruglim stolom
- Između svakog para je **jedna viljuška**
- Filozof razmišlja ili jede
- Za jelo treba **dve viljuške** (leva i desna)
- **Cilj**: sprečiti deadlock i starvation
- **Izazov**: koordinacija pristupa deljenim resursima

### 67. Kako bi izgledala verzija problema pet filozofa koja bi se realistično mogla sresti tokom razvoja softvera?
Realistična verzija:
- **5 niti** koje dele **5 resursa** u kružnom rasporedu
- Svaka nit treba **2 susedna resursa** istovremeno
- Primer: **baza podataka sa tabelama** koje zahtevaju više lock-ova
- Primer: **distribuirani sistem** sa međusobno zavisnim komponentama
- Rešenje: numerisanje resursa, timeout, arbitrar

### 68. Šta je mrtva petlja?
Mrtva petlja (deadlock) je:
- Stanje gde **2 ili više procesa** čeka jedni na druge
- **Nijedan proces ne može napredovati**
- Procesi čekaju na resurse koje drže drugi procesi
- Sistem je blokiran
- Zahteva spoljašnju intervenciju

### 69. Po čemu se živa petlja razlikuje od mrtve petlje?
Razlika:
- **Mrtva petlja**: procesi blokirani, čekaju pasivno
- **Živa petlja** (livelock): procesi aktivni ali ne napreduju
- U živoj petlji procesi menjaju stanje ali ne postižu cilj
- Primer žive petlje: dva procesa ustupaju resurse jedni drugima u nedogled

### 70. Koji uslovi su potrebni za pojavu mrtve petlje?
**Coffman-ovi uslovi** (sva 4 moraju biti istovremeno ispunjena):
1. **Međusobna isključivost** - resursi se ne mogu deliti
2. **Hold and wait** - proces drži resurse i čeka na druge
3. **Bez preuzimanja** (no preemption) - resursi se ne mogu oduzeti
4. **Kružno čekanje** - postoji kružni lanac procesa koji čekaju

### 71. Kako se u praksi tretira problem mrtve petlje?
U praksi:
- **Ignorisanje** - najčešće (ostrich algorithm)
- **Sprečavanje** - eliminacija jednog od 4 uslova
- **Izbegavanje** - pametna dodela resursa (Banker's algorithm)
- **Otkrivanje i oporavak** - detektovanje i restart procesa

### 72. Na čemu se temelji sprečavanje mrtve petlje?
Temelji se na:
- **Eliminaciji barem jednog** od 4 Coffman-ova uslova
- Numerisanje resursa (sprečava kružno čekanje)
- Zahtevanje svih resursa odjednom (sprečava hold-and-wait)
- Omogućavanje preuzimanja resursa

### 73. Šta karakteriše izbegavanje mrtve petlje?
Karakteristike:
- **Dinamička provera** pre dodele resursa
- **Banker's algoritam** - proverava da li je stanje sigurno
- Zahteva poznavanje maksimalnih potreba procesa
- Dozvoljavaju se samo sigurne dodele

### 74. Šta karakteriše otkrivanje i oporavak od mrtve petlje?
Karakteristike:
- **Periodična provera** postojanja mrtve petlje
- **Graf čekanja** - detekcija ciklusa
- **Oporavak**: terminacija procesa ili preuzimanje resursa
- Overhead detekcije i gubitak rada

### 75. Šta karakteriše ignorisanje mrtve petlje?
Karakteristike:
- **Ostrich algorithm** - "glava u pesak"
- Pretpostavka da je deadlock redak
- Prepušta korisniku/administratoru da reaguje
- **Najčešći pristup** u praksi (Unix, Windows)

### 76. Opisati problem čitanja i pisanja
Problem:
- **Baza podataka** koju deli više procesa
- **Čitaoci** (readers) samo čitaju
- **Pisci** (writers) menjaju podatke
- **Pravila**:
  - Više čitalaca može istovremeno čitati
  - Pisac mora imati ekskluzivan pristup
  - Pisac i čitalac ne mogu biti istovremeno
- **Izazovi**: pravičnost, starvation

### 77. Šta karakteriše semafor?
Semafor:
- **Celobrojna promenljiva** za sinhronizaciju
- **Dve atomske operacije**: wait (P, down) i signal (V, up)
- Može biti **binarni** (0 ili 1) ili **generalni** (0 do N)
- **Ne može biti negativan**
- Koristi se za međusobnu isključivost i uslovljenu sinhronizaciju

### 78. Koje operacije su vezane za semafor?
Operacije:
- **wait(S) / P(S) / down(S)**: ako S>0 tada S--, inače čekaj
- **signal(S) / V(S) / up(S)**: S++, probudi jednu čekajuću nit
- **init(S, vrednost)**: inicijalizacija semafora
- Sve operacije su **atomske**

### 79. Kako semafor obezbeđuje sinhronizaciju međusobne isključivosti?
Međusobna isključivost:
```
semafor mutex = 1;

wait(mutex);
// kritična sekcija
signal(mutex);
```
- Inicijalizacija na **1**
- wait pre ulaska u kritičnu sekciju
- signal posle izlaska
- Samo jedna nit može biti u kritičnoj sekciji

### 80. Kako se obično implementira semafor?
Implementacija:
- **Celobrojna promenljiva** + **red čekanja**
- Atomske operacije pomoću hardvera (disable interrupts, test-and-set)
- U kernelu operativnog sistema
- Red blokiranih niti koje čekaju na semafor

### 81. U čemu se semafori razlikuju od isključivih regiona?
Razlike:
- **Semafori**: nizak nivo, fleksibilni, ručno upravljanje, skloni greškama
- **Isključivi regioni**: visok nivo, sigurniji, automatsko upravljanje (RAII)
- Semafori zahtevaju disciplinu programera
- Isključivi regioni integrisani u jezik

### 82. Koji semafori postoje?
Tipovi:
- **Binarni semafor** - vrednost 0 ili 1
- **Generalni (brojački) semafor** - vrednost 0 do N
- **Raspodeljeni binarni semafor** - za distribuirane sisteme

### 83. Šta karakteriše binarni semafor?
Karakteristike:
- Vrednost **0 ili 1**
- Funkcionalno sličan **mutex-u**
- Koristi se za međusobnu isključivost
- Jednostavniji od generalnog semafora

### 84. Šta karakteriše raspodeljeni binarni semafor?
Karakteristike:
- Semafor u **distribuiranom sistemu**
- Koordinacija između **više mašina**
- Zahteva **mrežnu komunikaciju**
- Složenija implementacija zbog latencije i grešaka

### 85. Šta karakteriše generalni semafor?
Karakteristike:
- Vrednost od **0 do N**
- **N** predstavlja broj dostupnih resursa
- Koristi se za **ograničen pool resursa**
- Primer: ograničavanje broja niti koje pristupaju resursu

### 86. Šta omogućuje raspodeljeni binarni semafor?
Omogućuje:
- Sinhronizaciju između **procesa na različitim mašinama**
- Distribuiranu međusobnu isključivost
- Koordinaciju u distribuiranim sistemima

### 87. Šta omogućuje binarni semafor?
Omogućuje:
- **Međusobnu isključivost** (mutex)
- **Signalizaciju** između niti
- Zaštitu kritičnih sekcija
- Jednostavnu sinhronizaciju

### 88. Šta omogućuje generalni semafor?
Omogućuje:
- **Ograničavanje broja** istovremenih pristupa
- Upravljanje **pool-om resursa**
- **Producer-consumer** problem sa ograničenim baferom
- Kontrolu pristupa deljenim resursima

### 89. Koje su prednosti i mane semafora?
**Prednosti:**
- Fleksibilni i moćni
- Efikasni
- Podržani u većini OS-ova
- Mogu rešiti različite probleme sinhronizacije

**Mane:**
- Nizak nivo apstrakcije
- Skloni greškama (zaboravljanje signal)
- Mogu dovesti do deadlock-a
- Teški za debugging
- Potrebna disciplina programera

### 90. Šta je lockless programiranje / programiranje bez zaključavanja?
Lockless programiranje:
- Tehnike **bez korišćenja lock-ova**
- Koristi **atomske operacije** (compare-and-swap, fetch-and-add)
- **Wait-free** ili **lock-free** algoritmi
- Izbegava blokiranje i deadlock
- Složenije za implementaciju

### 91. Šta je ABA problem?
ABA problem:
- **Nit A** pročita vrednost **A**
- **Nit B** promeni A→B→A
- **Nit A** misli da se ništa nije promenilo (vidi A)
- **Compare-and-swap** uspeva ali stanje možda nije isto
- Rešenje: **verzionisanje**, **DWCAS**

### 92. Šta je DWCAS i zašto je potreban?
DWCAS (Double-Width Compare-And-Swap):
- **Atomska operacija** nad **dva susedna memorijska slova**
- Rešava **ABA problem**
- Omogućava atomsku promenu **pokazivača + counter-a**
- Nije dostupan na svim arhitekturama

### 93. Šta su mane a šta prednosti programiranja bez zaključavanja / lockless programiranja?
**Prednosti:**
- Bez deadlock-a
- Bolje performanse (bez context switch)
- Bolji paralelizam
- Wait-free algoritmi garantuju napredak

**Mane:**
- **Veoma složeno** za implementaciju
- Teško za testiranje i debugging
- ABA problem
- Zahteva hardversku podršku
- Portabilnost

### 94. Do čega dovodi pokušaj niti da preuzme znak kada je cirkularni bafer drajvera tastature prazan?
Dovodi do:
- **Blokiranje niti** sve dok se ne pritisne taster
- Nit prelazi u **blokirano stanje**
- Čeka se na **interrupt od tastature**
- Posle interrupt-a nit se budi i preuzima znak

### 95. Šta se desi kada se napuni cirkularni bafer drajvera tastature?
Dešava se:
- **Novi znaci se gube** (buffer overflow)
- Ili se **blokira unos** dok se ne oslobodi mesto
- Često signal greške (beep)
- U nekim sistemima se prepisuju najstariji znaci

### 96. Šta se desi u obradi prekida diska?
U obradi prekida:
- **Interrupt handler** se pokreće
- Proverava se **status disk operacije**
- Podaci se **kopiraju** iz disk kontrolera u memoriju
- **Budi se nit** koja je čekala na operaciju
- Ažurira se stanje U/I operacije

## 4. Sistem Datoteka

### 97. Na šta ukazuje ime datoteke?
Ime datoteke ukazuje na:
- **Sadržaj ili svrhu** datoteke
- **Tip datoteke** (kroz ekstenziju)
- Logički identifikator za pristup
- Ljudima razumljiv naziv

### 98. Od koliko delova se sastoji ime datoteke?
Sastoji se od:
- **Imena** (base name)
- **Ekstenzije** (extension) - opciono
- Razdvojeno tačkom: `ime.ekstenzija`
- Primer: `dokument.txt`

### 99. Od koliko delova se sastoji ime imenika?
Sastoji se od:
- **Samo imena** (obično bez ekstenzije)
- Može imati ekstenziju u nekim sistemima
- Služi za organizaciju datoteka

### 100. Šta obuhvata rukovanje datotekom?
Obuhvata:
- **Kreiranje i brisanje** datoteka
- **Otvaranje i zatvaranje**
- **Čitanje i pisanje**
- **Promena atributa**
- **Promena pozicije** (seek)
- **Upravljanje pravima pristupa**

### 101. Šta karakteriše hijerarhijsku organizaciju datoteka?
Karakteristike:
- **Struktura drveta** (tree structure)
- **Direktorijumi/folderi** sadrže datoteke i poddirektorijume
- **Root direktorijum** na vrhu hijerarhije
- **Putanje** za navigaciju
- Bolja organizacija od ravne strukture

### 102. Šta važi za apsolutnu putanju?
Apsolutna putanja:
- Počinje od **root direktorijuma** (/ ili C:\)
- **Potpuna putanja** do datoteke
- **Nezavisna** od tekućeg direktorijuma
- Primer: `/home/user/file.txt` ili `C:\Users\file.txt`

### 103. Šta važi za relativnu putanju?
Relativna putanja:
- Počinje od **tekućeg direktorijuma**
- **Kraća** od apsolutne
- **Zavisi** od konteksta (pwd)
- Primer: `./folder/file.txt` ili `../file.txt`

### 104. Koje datoteke obrazuju sistem datoteka?
Obrazuju:
- **Obične datoteke** (regular files) sa podacima
- **Direktorijumi** (directories)
- **Specijalne datoteke** (devices, pipes, sockets)
- **Simbolički linkovi**
- Sve organizovano u jednu hijerarhiju

### 105. Koja su prava pristupa datotekama?
Osnovna prava:
- **Read (r)** - čitanje
- **Write (w)** - pisanje
- **Execute (x)** - izvršavanje
Za tri kategorije:
- **Owner** (vlasnik)
- **Group** (grupa)
- **Others** (ostali)

### 106. Koje kolone ima matrica zaštite?
Kolone:
- **Korisnici** (users) - redovi
- **Datoteke/resursi** - kolone
- Elementi su **prava pristupa** (r, w, x)

### 107. Čemu je jednak broj redova matrice zaštite?
Jednak je:
- **Broju korisnika** u sistemu
- Svaki red predstavlja jednog korisnika

### 108. Gde se mogu čuvati prava pristupa iz matrice zaštite?
Čuvaju se:
- **Uz datoteku** (Access Control List - ACL)
- **Uz korisnika** (Capability List)
- U **deskriptoru datoteke**
- U posebnim tabelama

### 109. Šta je potrebno za sprečavanje neovlašćenog menjanja matrice zaštite?
Potrebno:
- **Privilegovan pristup** (root/admin)
- **Zaštićeni sistemski pozivi**
- **Autentifikacija** korisnika
- Provera prava pre menjanja

### 110. Kada korisnici mogu posredno pristupiti spisku lozinki?
Mogu posredno pristupiti:
- Preko **SUID programa** (npr. passwd)
- Program se izvršava sa pravima **root-a**
- Korisnik ne vidi lozinke direktno
- Kontrolisan pristup zaštićenim resursima

### 111. Koju dužnost imaju administratori?
Dužnosti:
- **Održavanje sistema**
- **Upravljanje korisnicima** i pravima
- **Backup i recovery**
- **Instalacija softvera**
- **Bezbednost sistema**
- **Monitoring performansi**

### 112. Šta sadrži numerička oznaka korisnika?
Sadrži:
- **UID** (User ID) - jedinstveni broj korisnika
- **GID** (Group ID) - broj primarne grupe
- Koristi se interno u OS-u
- Mapira se na ime korisnika

### 113. Kakvu numeričku oznaku imaju saradnici vlasnika datoteke?
Imaju:
- **Isti GID** (Group ID) kao vlasnik
- Pripadaju **istoj grupi**
- Dele grupna prava pristupa

### 114. Kakvu numeričku oznaku imaju ostali korisnici?
Imaju:
- **Različit UID i GID** od vlasnika
- Ne pripadaju grupi datoteke
- Primenjuju se prava za "others"

### 115. Kada se obavlja provera prava pristupa datoteci?
Provera se obavlja:
- Pri **otvaranju datoteke** (open)
- Pre svake **operacije pristupa**
- U vreme **sistema poziva**
- Koriste se UID/GID pozivajućeg procesa

### 116. Čime se bavi sigurnost?
Sigurnost se bavi:
- **Zaštitom od neovlašćenog pristupa**
- **Autentifikacijom** korisnika
- **Autorizacijom** (prava pristupa)
- **Enkripcijom** podataka
- **Integritetom** sistema
- **Auditovanjem**

### 117. Kako se predstavlja sadržaj datoteke?
Predstavlja se kao:
- **Niz bajtova** (byte stream)
- **Blokovi** fiksne veličine na disku
- Logički: kontinualni prostor
- Fizički: može biti rasut po disku

### 118. Gde se javlja interna fragmentacija?
Javlja se:
- Unutar **poslednjeg bloka** datoteke
- Kada datoteka ne popunjava ceo blok
- Gubitak prostora između kraja podataka i kraja bloka
- Zavisi od veličine bloka

### 119. Šta karakteriše kontinualne datoteke?
Karakteristike:
- Datoteka zauzima **uzastopne blokove** na disku
- **Brz pristup** (sekvencijalni i direktan)
- **Problem produženja** - teško dodati blokove
- **Eksterna fragmentacija**
- Slično dinamičkoj alokaciji memorije

### 120. Koji oblik evidencije slobodnih blokova masovne memorije je podesan za kontinualne datoteke?
Podesan je:
- **Linked list slobodnih regiona**
- Lista uzastopnih slobodnih blokova
- Brzo pronalaženje dovoljno velikog regiona
- Spajanje susednih slobodnih regiona

### 121. Šta je eksterna fragmentacija?
Eksterna fragmentacija:
- **Rasuti slobodni blokovi** po disku
- Ukupno dovoljno prostora, ali ne kontinualno
- Nemoguće alocirati veliku kontinualnu datoteku
- Zahteva **defragmentaciju**

### 122. Šta karakteriše rasute datoteke?
Karakteristike:
- Datoteka u **nekontinualnim blokovima**
- **Tabela pristupa** ili **indeksni blokovi**
- **Nema eksterne fragmentacije**
- **Lako produženje**
- Sporiji pristup (indirekcija)

### 123. Šta karakteriše tabelu pristupa?
Tabela pristupa:
- **Mapa logičkih blokova** na fizičke
- Jedan ulaz po **logičkom bloku** datoteke
- Nalazi se na **disku ili u memoriji**
- Omogućava direktan pristup blokovima

### 124. Šta ulazi u sastav tabele pristupa?
Sastav:
- **Logički broj bloka** (indeks)
- **Fizički broj bloka** (adresa na disku)
- Može biti u **deskriptoru** ili **posebnom bloku**

### 125. Kada rasuta datoteka ne zauzima više prostora na disku od kontinualne datoteke?
Kada:
- **Tabela pristupa** stane u deskriptor
- Nema dodatnih indeksnih blokova
- Mala datoteka sa direktnim pokazivačima

### 126. Koji oblik evidencije slobodnih blokova masovne memorije je podesan za rasute datoteke?
Podesan je:
- **Bit mapa** (bitmap) - jedan bit po bloku
- **Linked list** pojedinačnih blokova
- Brzo pronalaženje pojedinačnih slobodnih blokova

### 127. Kada dolazi do gubitka blokova prilikom produženja rasute datoteke?
Dolazi kada:
- **Sistem padne** tokom dodavanja blokova
- Blokovi dodati na disk ali **ne u tabelu pristupa**
- Blokovi označeni zauzeti ali nedostupni
- Zahteva fsck (file system check)

### 128. Kada dolazi do višestrukog nezavisnog korišćenje istog bloka prilikom produženja rasute datoteke?
Dolazi kada:
- **Sistem padne** tokom ažuriranja
- Isti blok dodeljen **dvema datotekama**
- Nekonzistentna stanja tabele pristupa
- Ozbiljna greška - korupcija podataka

### 129. Kada pregled izmena ukazuje da je sistem datoteka u konzistentnom stanju?
Ukazuje kada:
- **Svaki blok** je ili slobodan ili dodeljen **tačno jednoj datoteci**
- **Broj blokova** u datotekama + slobodni = ukupno blokova
- Nema izgubljenih ili višestruko dodeljenih blokova
- Strukture podataka konzistentne

### 130. Kako se ubrzava pristup datoteci?
Ubrzava se:
- **Keširanjem** nedavno korišćenih blokova u RAM
- **Read-ahead** (prefetch) - čitanje unapred
- **Write-behind** (delayed write) - odloženo pisanje
- **Buffer cache** u operativnom sistemu

### 131. Od čega zavisi veličina bloka?
Zavisi od:
- **Trade-off**: interna fragmentacija vs. broj blokova
- Tipično **512B - 8KB**
- Veći blok: manje indirektnih pristupa, više fragmentacije
- Manji blok: više pristupa, manje fragmentacije

### 132. Šta sadrži deskriptor kontinualne datoteke?
Sadrži:
- **Početnu adresu** (broj prvog bloka)
- **Dužinu** (broj blokova)
- Ostale atribute (vlasnik, prava, vreme)
- Jednostavan i mali deskriptor

### 133. Kako se rešava problem eksterne fragmentacije?
Rešava se:
- **Defragmentacijom** diska
- Premestanjem datoteka u kontinualne regione
- Periodično održavanje
- Sporo i zahteva vreme

### 134. Kako se ublažava problem produženja kontinualne datoteke?
Ublažava se:
- **Alokacijom dodatnog prostora** unapred
- Ostavljanje **gap-a** posle datoteke
- **Preusmeravanje** na novi region
- Korišćenje **rasutih datoteka** umesto kontinualnih

### 135. Šta sadrži deskriptor rasute datoteke?
Sadrži:
- **Pokazivače na blokove** (direktne, indirektne)
- Ili **pokazivač na tabelu pristupa**
- **Veličinu datoteke**
- Ostale atribute
- Složeniji od kontinualne datoteke

### 136. Šta je imenik?
Imenik (direktorijum) je:
- **Specijalna datoteka** sa listom ulaza
- Svaki ulaz: **ime → deskriptor/i-node**
- Organizuje datoteke
- Može sadržati podimenikе

### 137. Šta karakteriše specijalne datoteke?
Karakteristike:
- Reprezentuju **uređaje** (devices)
- **Blokovske** (disk) ili **znakovne** (tastatura)
- Pristup kao običnim datotekama (read/write)
- U `/dev` direktorijumu (Unix)

### 138. Šta sadrži deskriptor specijalne datoteke?
Sadrži:
- **Major number** - tip drajvera
- **Minor number** - konkretni uređaj
- **Tip** (blokovski/znakovni)
- Prava pristupa

### 139. Šta omogućuju blokovske specijalne datoteke?
Omogućuju:
- Pristup **disk particijama** kao datotekama
- **Direktan pristup** blokovima
- Koristi se za **formatting**, **backup**
- Primer: `/dev/sda1`

### 140. Šta omogućuje rukovanje particijama?
Omogućuje:
- **Logičku podelu** fizičkog diska
- **Različite sisteme datoteka** na istom disku
- **Izolaciju** različitih OS-ova
- **Multi-boot** konfiguracije

## 5. Upravljanje Memorijom

### 141. Kakav može biti logički adresni prostor?
Može biti:
- **Kontinualni** (linearan)
- **Segmentiran** (više segmenata)
- **Stranični** (podela na stranice)
- **Stranično-segmentiran** (kombinacija)

### 142. Šta karakteriše kontinualni logički adresni prostor?
Karakteristike:
- **Jedan linearan prostor** adresa
- Jednostavna translacija (baza + offset)
- Ceo proces u kontinualnoj memoriji
- Eksterna fragmentacija

### 143. Šta karakteriše segmentirani logički adresni prostor?
Karakteristike:
- Proces podeljen na **logičke segmente**
- Segment = kod, podaci, stek, heap
- **Različite veličine** segmenata
- Svaki segment nezavisno alociran
- Eksterna fragmentacija

### 144. Šta karakteriše stranični logički adresni prostor?
Karakteristike:
- Podela na **stranice fiksne veličine**
- **Tabela stranica** za translaciju
- **Nema eksterne fragmentacije**
- Interna fragmentacija (poslednja stranica)
- Najčešći pristup danas

### 145. Šta karakteriše stranično segmentirani logički adresni prostor?
Karakteristike:
- **Kombinacija** straničnog i segmentiranog
- Segmenti podeljeni na stranice
- **Dvostepena translacija**: segment → stranica → fizička adresa
- Složenije ali fleksibilnije

### 146. Šta karakteriše translacione podatke?
Translacioni podaci:
- **Mapiranje** logičkih u fizičke adrese
- **Tabele stranica** ili **tabele segmenata**
- Čuvaju se u memoriji i registrima (TLB)
- Neophodni za pristup memoriji

### 147. Šta karakteriše translaciju logičkih adresa kontinualnog logičkog adresnog prostora u fizičke?
Translacija:
- **Fizička = Baza + Logička adresa**
- Registar **baze** sadrži početnu fizičku adresu
- Provera **granice** (limit register)
- Jednostavna i brza

### 148. Koji logički adresni prostor se koristi kada veličina fizičke radne memorije prevazilazi potrebe procesa?
Koristi se:
- **Kontinualni** logički prostor
- Nema potrebe za virtuelnom memorijom
- Jednostavnija implementacija
- Ceo proces stane u RAM

### 149. Šta karakteriše segmentaciju?
Segmentacija:
- **Logičke jedinice**: kod, stack, heap, podaci
- **Različite veličine** segmenata
- **Tabela segmenata**: baza + limit
- Podrška za **deljenje** (shared libraries)
- Eksterna fragmentacija

### 150. Šta sadrže elementi tabele stranica?
Elementi sadrže:
- **PFN** (Page Frame Number) - broj fizičke stranice
- **Present bit** - da li je u RAM-u
- **Dirty bit** - da li je modifikovana
- **Referenced bit** - da li je pristupana
- **Protection bits** - prava pristupa (r/w/x)

### 151. Šta karakteriše virtuelni adresni prostor?
Karakteristike:
- **Veći od fizičke memorije**
- Stranice na **disku** (swap)
- **Stranični prekidi** (page faults)
- **Demand paging** - učitavanje po potrebi
- Iluzija neograničene memorije

### 152. Po kom principu se prebacuju kopije virtuelnih stranica?
Prebacuju se:
- **Demand paging** - učitavanje tek kada se pristupa
- **Prefetching** - anticipativno učitavanje
- **Page replacement algoritmi** - izbacivanje retko korišćenih
- Između RAM-a i swap prostora

### 153. Šta karakteriše straničnu segmentaciju?
Karakteristike:
- **Segmenti** podeljeni na **stranice**
- Tabela segmenata pokazuje na tabele stranica
- **Najbolje od oba sveta**
- Logička organizacija + nema eksterne fragmentacije
- Složenije za implementaciju

### 154. Kako se deli fizička radna memorija?
Deli se na:
- **Page frames** - okvire fiksne veličine
- Tipično **4KB** po frame-u
- Numerisani od 0 do N-1
- Dodeljuju se stranicama procesa

### 155. Kako se deli virtuelni adresni prostor?
Deli se na:
- **Virtuelne stranice** fiksne veličine
- Ista veličina kao page frame
- Numerisane od 0 dalje
- Mapiraju se na page frames ili disk

### 156. U kom obliku može biti evidencija slobodne fizičke memorije?
Oblici:
- **Bit mapa** - jedan bit po frame-u
- **Linked list** slobodnih frame-ova
- **Stack** slobodnih frame-ova
- **Buddy system**

### 157. Kod kog adresnog prostora se javlja eksterna fragmentacija?
Javlja se kod:
- **Segmentiranog** adresnog prostora
- **Kontinualnog** adresnog prostora
- **NE javlja se** kod straničnog

### 158. Kako se nazivaju skupovi fizičkih stranica, koji se dodeljuju procesima?
Nazivaju se:
- **Working set** - radni skup
- **Resident set** - rezidentni skup
- Skup page frame-ova dodeljenih procesu

### 159. Kada treba proširiti skup fizičkih stranica procesa?
Treba proširiti kada:
- **Česti stranični prekidi** (thrashing)
- Working set proces raste
- Proces aktivno koristi više stranica
- Loše performanse zbog swapping-a

### 160. Kada treba smanjiti skup fizičkih stranica procesa?
Treba smanjiti kada:
- Proces **retko koristi** dodeljene stranice
- **Nedostatak** fizičke memorije
- Referenced biti pokazuju nekorišćenje
- Drugi procesi trebaju memoriju

### 161. Kada ne treba menjati veličinu skupa fizičkih stranica procesa?
Ne treba menjati kada:
- **Stabilan working set**
- Nema straničnih prekida
- Proces efikasno koristi dodeljene stranice
- Dovoljno fizičke memorije

### 162. Koji pristupi oslobađanja fizičkih stranica obezbeđuju smanjenje učestanosti straničnih prekida nakon povećanja broja fizičkih stranica procesa?
Pristupi:
- **LRU** (Least Recently Used)
- **Clock algoritam**
- **Working set algoritam**
- Izbacuju se retko korišćene stranice

### 163. Koji pristupi oslobađanja fizičkih stranica koriste bit referenciranja?
Koriste:
- **Clock algoritam** (second chance)
- **NRU** (Not Recently Used)
- **Working set algoritam**
- Referenced bit pokazuje pristup

### 164. Koji pristupi oslobađanja fizičkih stranica koriste bit izmene?
Koriste:
- **NRU** - kombinuje referenced i dirty
- **Clock algoritam** - preferira čiste stranice
- Dirty stranice zahtevaju pisanje na disk

## 6. Raspoređivanje

### 165. Šta karakteriše tipične ciljeve raspoređivanja?
Ciljevi:
- **Fairness** - pravičnost
- **Propusnost** - maksimalan broj završenih procesa
- **Vreme odziva** - minimalno čekanje
- **Iskorišćenost procesora** - maksimalna
- **Minimizacija vremena obrtaja** (turnaround time)

### 166. Šta je cilj raspoređivanja za neinteraktivno korišćenje računara?
Cilj:
- **Maksimalna propusnost** (throughput)
- **Minimalno vreme obrtaja**
- Batch processing
- Ne mora brz odziv

### 167. Šta je cilj raspoređivanja za interaktivno korišćenje računara?
Cilj:
- **Minimalno vreme odziva**
- **Responsiveness** - brza reakcija
- Pravičnost između korisnika
- Izbegavanje izgladnjivanja

### 168. Zašto je uvedeno kružno raspoređivanje?
Uvedeno jer:
- **Pravična podela** procesorskog vremena
- Sprečava **starvation**
- Dobro za **time-sharing** sisteme
- Svi procesi dobijaju kvantum

### 169. Šta doprinosi ravnomernoj raspodeli procesorskog vremena?
Doprinosi:
- **Round-robin** raspoređivanje
- **Jednaki kvantumi** za sve procese
- **FIFO red** spremnih procesa
- Rotacija kroz sve procese

### 170. Šta je cilj raspoređivanja za multimedijalne aplikacije?
Cilj:
- **Garantovano vreme odziva** (real-time)
- **Minimalan jitter** (varijacija kašnjenja)
- **Deadline scheduling**
- Predvidljivo ponašanje

### 171. Do čega dovodi skraćenje kvantuma?
Dovodi do:
- **Bolji odziv** sistema
- **Više context switch-ova** (overhead)
- U ekstremnom slučaju: samo context switching
- Optimum: 10-100ms

### 172. Šta se postiže uticanjem na nivo prioriteta i na dužinu kvantuma?
Postiže se:
- **Favorizovanje** važnijih procesa
- **Razlikovanje I/O-bound** od CPU-bound
- **Adaptivno raspoređivanje**
- Bolje performanse za različite tipove aplikacija
- Multi-level feedback queue

### 173. Šta karakteriše operativne sisteme realnog vremena?
Karakteristike:
- **Garantovani rokovi** (deadlines)
- **Predvidljivo ponašanje**
- **Hard real-time**: propuštanje roka katastrofalno
- **Soft real-time**: propuštanje roka nepoželjno ali prihvatljivo
- Prioritetno raspoređivanje
- Minimalna latencija

### 174. Šta karakteriše multiprocesorske operativne sisteme?
Karakteristike:
- **Više procesora/jezgara**
- **SMP** (Symmetric Multiprocessing) - svi procesori jednaki
- **NUMA** (Non-Uniform Memory Access)
- **Load balancing** između procesora
- **Processor affinity** - preferiranje istog procesora
- Skalabilnost

## 7. Distribuirani Sistemi

### 175. Koje module sadrži mikrokernel?
Moduli:
- **Minimalni kernel**: IPC, osnovni scheduling, memorija
- **Serveri u korisničkom prostoru**: file system, network, drivers
- **Message passing** između komponenti
- Modularnost i fleksibilnost
- Primer: Mach, L4, QNX

### 176. Šta karakteriše poziv udaljene operacije (RPC)?
RPC (Remote Procedure Call):
- **Poziv funkcije na drugoj mašini**
- Izgleda kao **lokalni poziv**
- **Client-server** arhitektura
- Transparentnost distribucije
- Marshalling/unmarshalling parametara

### 177. Šta radi klijentski potprogram?
Klijentski potprogram (stub):
- **Pakuje parametre** (marshalling)
- **Šalje zahtev** serveru
- **Čeka na odgovor**
- **Raspakuje rezultat** (unmarshalling)
- Vraća rezultat pozivajućoj funkciji

### 178. Za šta su zaduženi serverski potprogrami?
Serverski potprogrami (skeleton):
- **Prijem zahteva** od klijenta
- **Raspakivanje parametara**
- **Poziv stvarne funkcije**
- **Pakovanje rezultata**
- **Slanje odgovora** klijentu

### 179. Koji problemi su vezani za poziv udaljene operacije?
Problemi:
- **Mrežne greške** - gubitak paketa, timeout
- **Heterogenost** - različite arhitekture, endianness
- **Performanse** - latencija mreže
- **Semantika** - at-least-once, at-most-once, exactly-once
- **Bind operacija** - pronalaženje servera

### 180. Šta podrazumeva dinamičko linkovanje klijenta i servera?
Podrazumeva:
- **Pronalaženje servera** u runtime-u
- **Name service** ili **registry**
- Fleksibilnost - server može biti bilo gde
- **Bind operacija** pri svakom pozivu ili jednom

### 181. Koje operacije podržava protokol razmene poruka između klijenta i servera?
Operacije:
- **send** - slanje poruke
- **receive** - prijem poruke
- **request-reply** - zahtev-odgovor par
- **acknowledge** - potvrda prijema
- **timeout** i **retry** mehanizmi

### 182. Za šta su zadužene sistemske operacije koje ostvaruju protokol razmene poruka?
Zadužene za:
- **Transport poruka** preko mreže
- **Routing** do odredišta
- **Flow control**
- **Error detection** i **recovery**
- **Buffering** poruka

### 183. Šta sadrže poruke koje razmenjuju klijent i server?
Poruke sadrže:
- **Header**: tip poruke, ID, sekvencijski broj
- **Identifikator operacije**
- **Parametre** funkcije (marshalled)
- **Rezultat** (u odgovoru)
- **Status kod**

### 184. Šta je potrebno za sigurnu razmenu poruka između klijenta i servera?
Potrebno:
- **Enkripcija** poruka (SSL/TLS)
- **Autentifikacija** klijenta i servera
- **Digitalni potpis** za integritet
- **Sertifikati**
- **Autorizacija** - provera prava

### 185. Šta karakteriše digitalni potpis?
Karakteristike:
- **Asimetrična kriptografija**
- Potpis **privatnim ključem**, verifikacija **javnim**
- Garantuje **autentičnost** pošiljaoca
- Garantuje **integritet** poruke
- **Non-repudiation** - ne može se poricati

### 186. Od čega zavisi propusnost servera?
Zavisi od:
- **Broj niti/procesa** servera
- **Brzina obrade** zahteva
- **Propusnost mreže**
- **Konkurentni klijenti**
- Arhitektura: iterativni vs. konkurentni server

### 187. Šta sadrže dozvole na kojima se zasniva zaštita datoteka u distribuiranom sistemu?
Dozvole sadrže:
- **Identitet korisnika**
- **Prava pristupa** (read, write, execute)
- **Digitalni potpis** servera
- **Rok važenja** (expiration)
- **Scope** - koje datoteke pokriva

### 188. Šta karakteriše distribuiranu sinhronizaciju?
Karakteristike:
- **Logički satovi** (Lamport timestamps)
- **Distribuirani algoritmi** za mutual exclusion
- **Consensus protokoli** (Paxos, Raft)
- **Vektorski satovi** za causality
- Složenije od centralizovane sinhronizacije

### 189. Šta karakteriše distribuirani računarski sistem?
Karakteristike:
- **Više računara** povezanih mrežom
- **Deljenje resursa**
- **Transparentnost**: lokacije, pristupa, konkurentnosti
- **Skalabilnost**
- **Fault tolerance**

### 190. Šta karakteriše distribuiranu softversku platformu?
Karakteristike:
- **Middleware** između OS-a i aplikacija
- **RPC/RMI** (Remote Method Invocation)
- **Message-oriented middleware** (MOM)
- **Web services** (REST, SOAP)
- Apstrakcija distribucije

## 8. Komandni Jezici

### 191. Od čega se sastoje komande znakovnog komandnog jezika?
Sastoje se od:
- **Ime komande/programa**
- **Argumenti** (opcije i parametri)
- **Operatori** (|, >, <, &&, ||)
- **Whitespace** kao separator
- Primer: `ls -la /home`

### 192. Kako se zadaju komande grafičkih komandnih jezika?
Zadaju se:
- **Klikom miša** na ikone
- **Drag & drop**
- **Meniji** (drop-down, context)
- **Dijalozi** sa poljima
- GUI komponente (buttons, checkboxes)

### 193. Šta su ciljevi znakovnih komandnih jezika?
Ciljevi:
- **Automatizacija** pomoću skripta
- **Moćne alate** za obradu teksta
- **Pipeline** - povezivanje komandi
- **Efikasnost** za napredne korisnike
- **Repeatability** - ponavljanje zadataka

### 194. Šta omogućuju znakovni komandni jezici?
Omogućuju:
- **Batch obrada**
- **Skriptovanje** (shell scripts)
- **Automatizacija** administrativnih zadataka
- **Kombinovanje alata** (pipes)
- **Remote pristup** (SSH)

### 195. Šta omogućuje preusmeravanje?
Preusmeravanje omogućuje:
- **Promena ulaza/izlaza** programa
- **> datoteka** - izlaz u datoteku
- **< datoteka** - ulaz iz datoteke
- **>> datoteka** - append u datoteku
- **2> datoteka** - stderr u datoteku

### 196. Čemu služi pipe?
Pipe (|) služi za:
- **Povezivanje izlaza** jedne komande sa **ulazom** druge
- **Pipeline** obrada podataka
- Primer: `cat file.txt | grep "pattern" | sort`
- Efikasna obrada bez privremenih datoteka

### 197. Čemu služi baferovana specijalna datoteka?
Služi za:
- **Named pipe** (FIFO)
- **IPC** između procesa
- **Buffering** podataka
- Procesi komunikuju kroz datoteku
- Primer: `mkfifo mypipe`

### 198. Šta karakteriše pozadinske procese?
Karakteristike:
- Izvršavaju se **u pozadini** (background)
- **Ne blokiraju shell**
- Zahtevaju **&** na kraju komande
- **Daemon** procesi
- Primer: `command &`

### 199. Šta karakteriše komandne datoteke?
Komandne datoteke (shell scripts):
- **Skripte** sa sekvencama komandi
- **Interpretiraju se** od strane shell-a
- **Automatizacija** zadataka
- **Kontrola toka** (if, for, while)
- **Promenljive** i funkcije

### 200. Šta omogućuju korisničke komande?
Omogućuju:
- **Rad sa datotekama** (cp, mv, rm)
- **Pregled sistema** (ps, top)
- **Obrada teksta** (grep, sed, awk)
- **Kompilacija** (gcc, make)
- **Svakodnevne zadatke**

### 201. Šta omogućuju administratorske komande?
Omogućuju:
- **Upravljanje korisnicima** (useradd, passwd)
- **Upravljanje sistemom** (shutdown, reboot)
- **Instalacija softvera** (apt, yum)
- **Monitoring** (dmesg, journalctl)
- **Konfiguracija mreže** (ifconfig, ip)
- Zahtevaju **root privilegije**

### 202. Čime se bavi sigurnost?
Sigurnost se bavi:
- **Confidentiality** - tajnost podataka
- **Integrity** - integritet podataka
- **Availability** - dostupnost sistema
- **Authentication** - provera identiteta
- **Authorization** - kontrola pristupa
- **Accountability** - evidencija aktivnosti

## 9. Upravljanje Procesima - Detalji

### 203. Šta omogućuju sistemske operacije za rukovanje procesima?
Omogućuju:
- **Kreiranje** procesa (fork, exec)
- **Terminaciju** procesa (exit, kill)
- **Sinhronizaciju** (wait, waitpid)
- **IPC** (pipes, shared memory, signals)
- **Kontrolu izvršavanja** (pause, resume)

### 204. Šta obuhvata stvaranje procesa?
Stvaranje obuhvata:
- **Alokacija PCB** (Process Control Block)
- **Alokacija adresnog prostora**
- **Inicijalizacija PCB** atributa
- **Kopiranje ili deljenje** resursa roditelja
- **Ubacivanje u red spremnih** procesa

### 205. Šta obuhvata uništenje procesa?
Uništenje obuhvata:
- **Dealokacija resursa** (memorija, datoteke)
- **Zatvaranje otvorenih datoteka**
- **Uklanjanje iz reda** raspoređivanja
- **Oslobađanje PCB**
- **Obaveštenje roditelja** (SIGCHLD)

### 206. Šta sadrži slika procesa?
Slika procesa sadrži:
- **Kod** (text segment)
- **Podatke** (data segment) - inicijalizovani i neinicijalizovani
- **Stek** (stack) - lokalne promenljive, pozivi funkcija
- **Heap** - dinamički alocirana memorija
- **PCB** - deskriptor procesa

### 207. Za šta se koristi slobodna radna memorija procesa?
Koristi se za:
- **Heap** alokaciju (malloc, new)
- **Rast steka** (function calls)
- **Dinamičke strukture podataka**
- **Baferovanje** podataka
- **Privremene promenljive**

### 208. Koji atributi procesa postoje?
Atributi:
- **PID** - identifikator procesa
- **PPID** - identifikator roditelja
- **UID/GID** - vlasnik procesa
- **Prioritet** i stanje
- **Program counter** i registri
- **Otvorene datoteke**
- **Radni direktorijum**
- **Environment varijable**

### 209. Koje sistemske operacije za rukovanje procesima postoje?
Operacije:
- **fork()** - kreiranje procesa
- **exec()** - učitavanje novog programa
- **exit()** - terminacija
- **wait()/waitpid()** - čekanje na child
- **kill()** - slanje signala
- **getpid()/getppid()** - dobijanje ID-a

### 210. Koji se atributi nasleđuju od procesa stvaraoca prilikom stvaranja procesa?
Nasleđuju se:
- **UID/GID** - vlasništvo
- **Otvorene datoteke** (file descriptors)
- **Radni direktorijum**
- **Environment varijable**
- **Prioritet** (može se modifikovati)
- **Maska signala**

### 211. Koji se atributi procesa nastanu prilikom njegovog stvaranja?
Nastaju:
- **Novi PID**
- **PPID** - ID roditelja
- **Sopstveno procesorsko vreme** (CPU time = 0)
- **Novo stanje** (ready)
- **Sopstveni resource limits**

### 212. Šta karakteriše kopiju slike procesa?
Kopija slike (fork):
- **Identična slika** roditelju
- **Copy-on-write** (COW) optimizacija
- **Deljenje read-only stranica**
- Kopiranje tek pri **modifikaciji**
- Efikasnije od pune kopije

### 213. Koje raspoređivanje je vezano za zamenu slika/stranica procesa?
Vezano za:
- **Swapping** - zamena celih procesa
- **Paging** - zamena stranica
- **Dugoročno raspoređivanje** - izbor procesa za swap
- **Srednjeročno raspoređivanje** - upravljanje memorijom

### 214. Šta karakteriše rukovanje nitima unutar operativnog sistema?
Karakteristike:
- **Kernel threads** - OS upravlja nitima
- **Potpuna podrška** OS-a
- **Pravo paralelno** izvršavanje na više procesora
- **Sporije** kreiranje nego user threads
- **1:1 model** - svaka user nit mapirana na kernel nit

### 215. Šta karakteriše rukovanje nitima van operativnog sistema?
Karakteristike:
- **User-level threads** - biblioteka upravlja
- **Brže** kreiranje i context switch
- **N:1 model** - sve niti u jednom kernel procesu
- **Blokiranje jedne niti** blokira sve
- Primer: GNU Portable Threads

### 216. Šta karakteriše nulti proces?
Nulti proces (swapper/idle):
- **Kreiran pri boot-u** sistema
- **Ne izvršava korisnički kod**
- **Roditelj svih procesa** (indirektno)
- Aktivira se kada **nema spremnih procesa**
- **Uspavljuje procesor** (power saving)

### 217. Šta je karakteristično za proces dugoročni raspoređivač?
Dugoročni raspoređivač:
- **Bira procese** iz spool-a za učitavanje u memoriju
- **Kontroliše stepen multiprogramiranja**
- **Izvršava se retko** (minuti)
- **Balansira** CPU-bound i I/O-bound procese
- Manje važan u modernim sistemima

### 218. Šta radi proces identifikator?
Proces identifikator:
- Nije stvarni proces već **sistemska operacija**
- **Vraća PID** procesa (getpid())
- **Jedinstveni identifikator** u sistemu
- Koristi se za **slanje signala**, **wait** operacije

### 219. Ko stvara proces komunikator?
Stvara:
- **init/systemd** proces (PID 1)
- Ili bilo koji proces koji pokreće **IPC mehanizme**
- Serveri koji **slušaju na portovima**
- Daemon procesi za komunikaciju

### 220. Šta označava SUID (switch user identification)?
SUID označava:
- **Special permission bit** na izvršnim datotekama
- Program se izvršava sa **privilegijama vlasnika** datoteke
- **Privremeno povećanje** privilegija
- Primer: **passwd** program (needs root za /etc/shadow)
- **Sigurnosni rizik** ako se loše implementira

### 221. Šta karakteriše heš (hash/jednosmernu) funkciju?
Karakteristike:
- **Jednosmerna** - ne može se dobiti ulaz iz izlaza
- **Deterministička** - isti ulaz → isti izlaz
- **Brza** za računanje
- **Collision resistant** - teško naći dva različita ulaza sa istim izlazom
- Primer: **SHA-256**, MD5 (deprecated)
- Koristi se za **lozinke**, **integritet**

### 222. Šta karakteriše simetričnu kriptografiju?
Karakteristike:
- **Isti ključ** za enkripciju i dekripciju
- **Brza** (hardware podrška)
- **Problem razmene ključa** - kako bezbedno dostaviti?
- Primer: **AES**, DES, 3DES
- Koristi se za **bulk enkripciju**

### 223. Šta karakteriše asimetričnu kriptografiju?
Karakteristike:
- **Par ključeva**: javni i privatni
- **Javni ključ** za enkripciju
- **Privatni ključ** za dekripciju (i potpis)
- **Spora** (računski intenzivna)
- Rešava **problem razmene ključa**
- Primer: **RSA**, ECC, DSA
- Koristi se za **digitalne potpise**, **razmenu ključeva**

### 224. Na čemu se temelji tajnost kriptovanja?
Temelji se na:
- **Kerckhoffs-ovom principu**: sigurnost u **tajnosti ključa**, ne algoritma
- **Algoritam javno poznat** i testiran
- **Dužina ključa** - dovoljno dugačak da otežava brute force
- **Kriptografska jačina algoritma**
- **Kvalitet generatora slučajnih brojeva**
- **Matematička složenost** (npr. faktorizacija velikih brojeva za RSA)

---

## Zaključak

Ovaj dokument pokriva **224 pitanja** iz oblasti operativnih sistema, uključujući:
- Osnovne koncepte (datoteke, procesi, memorija)
- Konkurentnost i sinhronizaciju
- Upravljanje resursima
- Distribuirane sisteme
- Sigurnost i kriptografiju

Pitanja su organizovana po tematskim celinama sa detaljnim odgovorima za svako pitanje.