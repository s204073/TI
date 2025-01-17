//nr albumu:204073,ARiSS, gr2, sem1
//GRA TEKSTOWA NA TECHNOLOGIE INFORMACYJNE

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>



int tmp = 0;
int rng(int min, int max) {
    return(rand() % (max - min + 1)) + min;
}


int main()
{
    srand(time(NULL));
    system("chcp 852");
    setlocale(LC_ALL, "Polish");

    int n, k = 0, i = 0; // i - obecne po�o�enie(kolumna1); k - zczytuje i przekazuje i po�o�enie wynikaj�cr z wyboru;
    int a, b, c = 0;
    char rng_wybor;
    char wybor; //zczytuje A,a,B,b,C,c; 
    char imie[50];

    int matryca_przejsc[54][4] = {
        {0,1,12,22},
        {1,2,7,11},
        {2,2,2,2},
        {3,63,12,22},
        {4,3,3,3},
        {5,6,6,3},
        {6,3,3,3},
        {7,8,9,10},
        {8,63,12,22},
        {9,63,12,22},
        {10,63,12,22},
        {11,63,12,22},
        {12,13,15,16},
        {13,14,15,16},
        {14,1,12,22},
        {15,13,14,16},
        {16,18,17,14},
        {17,13,15,14},
        {18,20,19,14},
        {19,13,15,14},
        {20,62,21,14},
        {21,1,14,22},
        {22,14,23,24},
        {23,14,42,24},
        {24,25,27,26},
        {25,40,36,29},
        {26,31,41,29},
        {27,36,53,29},
        {28,25,27,26},
        {29,14,30,28},
        {30,14,42,28},
        {31,31,31,31},
        {32,34,34,14},
        {33,28,14,42},
        {34,35,35,14},
        {35,61,14,14},
        {36,34,42,14},
        {37,37,37,37},
        {38,38,38,38},
        {39,39,39,39},
        {40,97,97,97},
        {41,56,97,28},
        {42,14,44,43},
        {43,14,44,43},
        {44,49,45,45},
        {45,46,51,51},
        {46,48,47,47},
        {47,52,57,52},
        {48,58,58,58},
        {49,50,59,59},
        {50,60,59,59},
        {51,60,52,60},
        {52,44,14,55},
        {53,31,31,31}


    };

    // tablica_tekstow - zawiera opisy kazdej stacji (stacja to matryca_przejsc[0][i]) i wyswietla odpowiedni tekst i wybory; zawiera te� kilka dodatkowych miejsc na ewnetualne rozwiniecie gry
    char tablica_tekstow[69][1000] =
    { "Rozpoczynasz swoj� wymarzon� podr�. Zdecyduj si� gdzie chcesz si� uda� najpierw\033[0;33m\nA - Tupad�y \nB - ��czna\nC - Samokl�ski\033[0m",
    "\nUdajesz si� do wsi Tupad�y.\nNagle widisz jak dw�ch typk�w atakuje samotn� staruszk�. Wyrywaj� jej torebk� a ona nie ma jak si� broni�. \033[0;33m\nA - bronisz j�\nB - uciekasz\nC - korzystasz na tym\033[0m",
    "\nPodbiegasz rozjuszony bezczelno�ci� napastnik�w. Jest ich dw�ch, wi�c wiesz, �e nie b�dzie �atwo mimo tego zadajesz cios! \033[0;31m\nA - cios z lewej \nB - cios z prawej\nC - kopniak tylnymi kopytami \033[0m",
    "\nPowalasz swoich przeciwnik�w. Owa staruszka m�wi do ciebie \n\033[0;34mNawet nie wiesz ile ci zawdzi�czam m�ody cz�owieku\n\033[0mPrzyjrza�a ci si� dok�adniej i doda�a\n\033[0;34mA raczej koniu\nNieistotne z reszt�, nie wiem gdzie ci� droga poniesie ale przyjmij dwa ostrze�enia od starszej do�wiadczonej kobiety\n\033[1;92m\v1)w pobli�u znajduje si� niejaki Wilczy Szaniec, pod �adnym pozorem tam nie id�. Nikt z tamt�d jeszcze nie wr�ci�.\n2) wystrzegaj si� niejakiej ko�skiej trawki. Nawet je�li by ci� r�wie�nicy nak�aniali.\033[0m\n Ruszasz wi�c dalej, stajesz na rozdro�u:\033[0;33m\nA - Wilczy Szaniec \nB - ��czna \nC - Samokl�ski\033[0m",
    "\nTw�j cios okaza� si� nienajlepszy. Musisz im do�o�y�\033[0;33m\nA - kopniak w nog� \nB - uderzenie ogonem niczym biczem\nC - uderzenie g�ow� jak to tylko konie potrafi�\033[0m",
    "\nTw�j cios okaza� si� tragicznie s�aby. Musisz si� bardziej wysili� by pokona� swoich przeciwnik�w \033[0;33m\nA - kopniak w nog� \nB - uderzenie ogonem niczym biczem\nC - uderzenie g�ow� jak to tylko konie potrafi�\033[0m",
    "\nJu� lepiej! Ale jeszcze przeciwnicy si� trzymaj� na nogach (co jest niepo��dane), musisz u�y� najbardziej wyszukanych metod by ich ostatecznie pokona� \033[0;33m\nA - nadepni�cie na but\nB - pogilgotanie\nC - opowiedzenie najsuchszego suchara jaki �wiat s�ysza�\033[0m",
    "\nUciekasz. Wolisz si� nie miesza�. Szw�dasz si� po wsi targany wyrzutami sumienia, w ko�cu trafiasz na targ. Widzisz tam m�odego m�czyzn�, w kt�rym rozpoznajesz jednego z tych, co przed chwil� pobili staruszk�. \033[0;33m\nA - rozmawiasz z nim i tak\nB - zg�aszasz go na policj�\nC - odchodzisz i opuszczasz miasto\033[0m",
    "\nPodchodzisz do owego m�czyzny i t�umaczysz sw�j cel podr�y\n\033[0;34mSzukasz czego� do koniaku? S�uchaj bratku, dorzu� tam nieco ko�skiej trawki, po tym to dopiero jest ODLOT hehe\033[0m\nOpuszczasz wi�c wie�\033[0;33m\nA - Wilczy Szaniec \nB - ��czna \nC - Samokl�ski\033[0m",
    "\nNatychmiast przyt�oczony poczuciem winy, udajesz si�, by zg�osi�, to co widzia�e� na komisariat\nPolicjant m�wi\n\033[0;34mNaprawd� powiniene� jej pom�c, babcia Brygida to wspania�a kobieta. No nic, widz�, �e jeste� podr�nym.\nW pobli�u znajduje si� niejaki Wilczy Szaniec, pod �adnym pozorem tam nie id�. Nikt z tamt�d jeszcze nie wr�ci�.\nOpuszczasz wi�c wie�\033[0;33m\nA - Wilczy Szaniec \nB - ��czna \nC - Samokl�ski\033[0m",
    "\nOpuszczasz miasto i widzisz trzy znaki: \033[0;33m\nA - Wilczy Szaniec \nB - ��czna \nC - Samokl�ski\033[0m",
    "\nWyrzekasz si� swojego w�tpliwego cz�owiecze�stwa.\nPodbiegasz do szarpi�cej si� tr�jki. Wyrywasz torebk� i uciekasz na �lepo z wioski. Dobiegasz na skrzy�owanie i widzisz ukryt� dr�k� do Wilczego Sza�ca\nMy�lisz sobie:\033[0;36m\nTo chyba to, tam nikt mnie nie znajdzie!\033[0;33m\nA - Wilczy Szaniec \nB - ��czna \nC - Samokl�ski\033[0m",
    "\nTrafiasz do ��cznej.\nWidzisz miasto a� kipi. Protest trwa. Nie rozumiesz co si� dzieje, ale jeste� zaintrygowany. Chcesz si� czego� dowiedzie�, gdzie si� udajesz?\033[0;33m\nA - Urz�d miasta\nB - Targ\nC - Karczma\033[0m ",
    "\nWchodzisz do urz�du. Podchodzisz do biurka i u�miechasz si� do siedz�cej za nim sekretarki burmistrza.\n Zanim jednak zd��ysz si� wys�owi�, s�yszysz tylko:\033[0;34mTO NIE INFORMACJA TURYSTYCZNA\nBURMISTRZ JEST TERAZ BARDZO ZAJ�TY\nPROSZ� OPU�CI� URZ�D\033[0m\nNie masz zbytnio wyboru. \033[0;33m\nA - wychodzisz z miasta\nB - udajesz si� na targ\nC - idziesz do karczmy\033[0m ",
    "\nZnajdujesz si� na rozdro�u, zdecyduj, gdzie chcesz si� teraz si� uda�: \033[0;33m\nA - Tupad�y \nB - ��czna \nC - Samokl�ski\033[0m",
    "\nIdziesz na targ. Tam podchodzisz do najbardziej przyja�nie wygl�daj�cego sprzedawcy i zagadujesz \n\033[0;36mS�uchaj jestem przyjezdny, a widz�,�e macie tu niez�y raban, mo�esz mi wyja�ni� co si� w�a�ciwie dzieje\033[0;34m\nWitam Ci� w ��cznej, chcia�bym, ale nie mam czasu z Tob� po rozmawia�, je�li chcesz informacji udaj si� do karczmy.\033[0m\n Gdzie si� udajesz? \033[0;33m\nA - idziesz do urz�du\nB - wychodzisz z miasta\nC - udajesz si� do karczmy\033[0m",
    "\nWchodzisz do karczmy. Podchodzisz do lady i zagajasz stoj�cego za barem m�odego ch�opaka\n\033[0;36mNiez�y raban tu macie. Zawsze wiedzia�em, �e ��czna ma zaci�cie polityczne odk�d by� tu prezydent kiedy�.\n\033[0;34mAno, obecny burmistrz jest tragiczny, kradnie nasze pieni�dze,a nasza wioska ma problem by go przep�dzi� i wygra� z nim wybory. \033[0mS�ysz�c to rozwa�asz r�ne mo�liwo�ci: \033[0;33m\nA - startujesz na burmistrza\nB -\033[0;36mPrzykro mi to s�ysze�, chcia�bym pom�c, ale mam misj� \033[0;33m\nC - \033[0;36mHaha, sami so tego doprowadzili�cie. Na mmnie ju� czas\033[0m",
    "\n\033[0;34mMasz dobre serce, szkoda, �e nie mo�esz nam pom�c, jedynie co ci mog� powiedzie�, to �e moja babcia zwyk�a m�wi�, �e \033[1;92mprzy wytwarzaniu koniaku najlepiej go rozszczepi� atomowo dla pe�ni smaku. \n\033[0;34m Trzymaj si� \n\033[0mPodnosisz si� z miejsca i kierujesz do wyj�cia:\033[0;33m\nA - idziesz do urz�du\nB - idziesz na targ\nC - opuszczasz miasto\033[0m ",
    "\n\033[0;36mWystartuj�! Nie mog� was tak z tym zostawi�!\n\033[0;34mWow to naprawd� szlachetne z twojej strony, je�li jednak b�dziesz chcia� wr�ci� do swojej misji - pami�taj s�owa mojej babci - \033[1;92mnajlepszy na wydobycie smaku z koniaku jest rozszczep atomowy\033[0m \nZmotywowany tym decydujesz si� na kampani�, na czym chcesz si� skupi�?: \033[0;33m\nA - na komunikacji miejskiej, stworzenie rezerwatu dla dzik�w - tego tak zas�u�onego gatunku dla tego miasta i przywr�cenia miasta do stanu �wietno�ci\nB - na wzro�cie gospodarczym i wypromowanie miasta na terenie og�lnopolskim\nC - zestresowany, rezygnujesz z pomys�u i opuszczasz miasto\033[0m ",
    "\nNiestety, obrana przez ciebie kampania, nie przekona�a ��cznian�w i ��cznianki. Przegra�e� wybory. W ��cznej zn�w zapanowa�a dyktatura. Przypominasz se jednak o swojej misji i bogatszy o wiedz� i do�wiadczenie ruszasz w dalsz� podr�: \033[0;33m\nA - Tupad�y \nB - ��czna \nC - Samokl�ski\033[0m",
    "\nPrzeprowadzasz �wi�tn� kampani�, zjednaj�c sobie wszystkich ��cznian�w i ��cznianki. Wygrywasz wybory. \n Stajesz jednak przed powa�nym wyborem:\033[0;33m\nA - po�wi�casz swoje �ycie burmistrzowaniu \nB - pracujesz ci�ko kilka lat jako burmistrz ale ostatecznie przypominasz se o swojej misji\nC - abdykujesz i uciekasz\033[0m ",
    "\nNaprawd� przywi�za�e� si� do ��cznej, �wiadomy jeste� jednak, �e du�o dla nich zrobi�e�, wybudowa�e� linie tramwajowe, zaj��e� si� tematem dzik�w, przywr�ci�e� nadziej� w sercach ��cznian, a wiedz�c, �e nie jeste� stworzony na burmistrza, ruszasz dalej w �wiat: \033[0;33m\nA - Tupad�y \nB - opu�� miasto \nC - Samokl�ski\033[0m",
    "\nUdajesz si� do wsi Samokl�ski. Od razu po wej�ciu na obszar wsi czujesz zbiorowe podniecenie i atmosfer� oczekiwania. Nie musisz d�ugo czeka�, by dowiedzie� si� o co chodzi, plakaty og��szaj�ce mi�dzywsiowy konkurs talent�w wisz� dos�owmnie WSZ�DZIE, z rozbawieniem dostrzegasz nawet jakiego� p�dr�ka biegn�cego z kartk� przyklejon� do plec�w. \033[0;33m\nA - opuszczasz miasto\nB - idziesz dalej\nC - bierzesz udzia�\033[0m",
    "\nIdziesz i idziesz po wsi, ale ca�a spo�eczno��, powi�kszona o przyjezdznych �yje owym konkursem talent�w: \033[0;33m\nA - opuszczasz miasto\nB - idziesz do domu\nC - bierzesz udzia�\033[0m",
    "\nZdecydowa�e� si� wzi�� udzia�  w konkursie. Musisz si� zastanowi� nad swoimi talentami. W jakich kategoriach jeste� rozwini�ty?:\033[0;33m\nA - muzycznych\nB - intelektualnych\nC - ruchowych\033[0m ",
    "\nZdolno�ci muzyczne. Wybierz jaki wyst�p zaprezentujesz: \033[0;33m\nA - taniec\nB - gra na perkusji\nC - granie na kieliszkach z wod�\033[0m",
    "\nZdolno�ci ruchowe czy te� kinetyczne. Wybierz jaki wyst�p zaprezentujesz:\033[0;33m\nA - hobby horsing\nB - akrobacje w stroju spidermana\nC - bieg przez p�otki\033[0m",
    "\n\nZdolno�ci intelektualne. Wybierz jaki wyst�p zaprezentujesz: \033[0;33m\nA - recytacja rozwini�cia liczby Pi\nB - deklamacja poematu\nC - wyst�p magiczny/iluzjonistyczny\033[0m",
    "\nPr�bujesz ponownie swoich si�. Rozwa�asz ponownie swoje mocne i s�abe strony. W jakich kategoriach jeste� rozwini�ty?:\033[0;33m\nA - muzycznych\nB - intelektualnych\nC - ruchowych\033[0m ",
    "\nWidownia nie pochwali�a twojego wyst�pu, wsz�dzie by�o s�ycha� buczenie niezadowolonej widowni, nie wiesz jak sobie z tym poradzi� \033[0;33m\nA - uciekasz w smutku z miasta\nB - udajesz si� z innymi przegranymi na herbat� na pocieszenie\nC - pr�bujesz ponownie\033[0m",
    "\nWybierasz si� z innymi przegranymi na herbat�, w�r�d przyjemnych rozm�w dowiadujesz si�, �e regionalnym specyfikiem u�ywanym w wytwarzaniu koniaku jest \033[1;92mpodej�rzon ksi�ycowy\033[0mPocieszony i wzbogacony o now� wiedz� stajesz przed decyzj�: \033[0;33m\nA - opuszczasz miasto\nB - idziesz do domu\nC - wracasz na konkurs, ponownie spr�bowa� swoich si�\033[0m ",
    "\nWykonujesz wspania�y wyst�p. Dostajesz si� do fina�u, a o twojej potencjalnej wygranej zdecyduje teraz widownia. Z niecierpliwo�ci� czekasz na wynik...",
    "\nWi�kszo�ci� g�os�w widownii wygrywasz!!!! Otrzymujesz nagrod� pieni�n�, a burmistrz Samokl�ski s�ysz�c o twojej misji przekazuje ci tajny lokalny sk�adnik -\033[1;92mpodej�rzon ksi�ycowy\033[0m. \033[0;33m\nA - oblewasz szampana\nB - podskakujesz, rz��c rado�nie\nC - przyt�oczony presj� uciekasz\033[0m ",
    "\nNiestety nie ty wygra�e� fina�. \033[0;33m\nA - nie poddajesz si�, pr�bujesz ponownie\nB - opuszczasz miasto\nC - idziesz do domu\033[0m",
    "\nPubliczno�� domaga si� bisu.\nDooko�a ciebie s�yszysz tylko \033[0;34mBIS BIS BIS wi�cej! wi�cej!! TAK!!! NIECH ON TO ZROBI JESZCZE RAZ!!!!!\033[0;33m\nA - wykonujesz sw�j wyst�p ponownie\nB - dzi�kujesz zgromadzonym i wyg��szasz mow�\nC - k�aniasz si� i po angielsku schodzisz ze sceny\033[0m",
    "\nWszyscy s� pod wra�eniem, chc� wi�cej i wi�cej. Podchodzi do ciebie elegancko ubrana kobieta \033[0;34mWow, to naprawd� tw�j �ywio�, powiniene� si� na tym skupi�, jako sw�j zaw�d.\nTak si� sk�ada, �e jestem agentk� firmy bior�cej pod swoje skrzyd�a talenty takie jak ty.\033[0m\nNagle ona wyci�ga zza plecy gotow� umow� \033[0;33m\nA - podpisujesz z ni� umow�, przprzyjmuj�c sw�j talent na sw�j zaw�d\nB - \033[0;36mDzi�kuj� ci bardzo, ale mam misj�, na kt�ej mi bardzo zale�y, niestety musz� odrzuci� twoj� propozycj� \033[0;33m\nC - odchodzisz i opuszczasz miasto\033[0m",
    "\nOtrzymujesz z�oty przycisk. Widownia szaleje. Wsz�dzie ludzie klaszcz� i tupi�. Burmistrz wr�cza ci kompedium wiedzy o koniaku, z kt�rego dowiaduejsz si�, �e �eby otrzyma� najlepszy na �wiecie koaniak nale�y\033[1;92m\n1)doda� do niego podej�rzon ksi�ycowy\n2)rozszczepi� go atomowo\n3)wystrzega� si� z�udnej ko�skiej trawki\033[0m \033[0;33m\nA - wychodzisz na scen� z zamiarem podziekowania widzom\nB - dzi�kujesz zgromadzony, ale informujesz, �e masz misj� i pozyskawszy potrzebn� wiedz� niezzw�ocznie udajesz si� do domu podj�� si� ugotowania najlepszego koniaku na �wiecie\nC - opuszczasz miasto\033[0m ",
    "\nNa scen� wchodzi zwyci�zca",
    "\ntmp",
    "\ntmp",
    "\nTa�czysz ale boli ci� noga",
    "\nZostajesz paj�kokoniem, bohaterem. Czujesz w sobie niezwyk�� moc i potrzeb� obrony s�abszych.\033[0;33m\nA - poddajesz si� temu obecw�adniaj�cemu uczuciu i decydujesz si� porzuci� wszytsko i p�j�� �ladami spidermana\nB - ignorujesz wo�anie i spokojnie wykonujesz sw�j wyst�p\nC - zmieniasz dyscypline\033[0m",
    "\nPo d�ugiej podr�y, wracasz do domu. Nadszed� czas na refleksj�.\nCzy uda�o ci si� uda�, wsz�dzie, gdzie chcia�e�?\033[0;33m\nA - Jeszcze nie wszystko uda�o mi si� zrobi�. Nie jestem gotowy\033[0;36m \n\033[0;33mWracasz na rozdro�e\nB - rozpoczynasz wyczekiwane gotowanie\nC - tkni�ty chandr� podchodzisz do mapy wisz�cej na �cianie\033[0m",
    "\nWidzisz wszystkie miejsca do kt�rych chcia�e� si� uda�. Do kt�rych podr� planowa�e� tygodniami. \033[0;33m\nA -wracasz na rozdro�e\nB - dostrzegasz Wilczy Szaniec, wcze�niej przez ciebie nie odwiedzony, i wyruszasz tam bez namys�u\nC - patrzysz z sadysfakcj� na to, co dokona�e� i rozpoczynasz gotowanie\033[0m",
    "\nUzbrojony w zebran� podczas podr�y wiedz�, rozpoczynasz gotowanie. Do przygotowanego uprzednio naparu wrzucasz pierwszy skladnik\033[0;33m\nA - ko�ska trawka\nB - mi�ta\nC - li�� z drzewa ksi�ycowego\033[0m",
    "\nWrzucasz drugi sk�adnik: \033[0;33m\nA - podej�rzon ksi�ycowy\nB - sza�wia\nC - herbata z dzikiego zachodu\033[0m",
    "\nWybierasz posmak napoju, co wrzucasz: \033[0;33m\nA - resztki meteorytu znalezione przez twojego dziadka w ogr�dku\nB - mieszanka cytrusowa\nC - coca cola\033[0m",
    "\nTeraz czas �eby� prawid�owo obrobi� przygotowan� przez ciebie mieszank�: \033[0;33m\nA - dmuchanie s�omk� tak aby byly b�belki\nB - rozszczep atomowy\nC - mieszanie przy stopniowym podrzegwaniu\033[0m",
    "\nTeraz czas �eby� prawid�owo obrobi� przygotowan� przez ciebie mieszank�: \033[0;33m\nA - dmuchanie s�omk� tak aby byly b�belki\nB - rozszczep atomowy\nC - mieszanie przy stopniowym podrzegwaniu",
    "\nWrzucasz drugi sk�adnik: \033[0;33m\nA - podej�rzon ksi�ycowy\nB - sza�wia\nC - herbata z dzikiego zachodu",
    "\nTeraz czas �eby� prawid�owo obrobi� przygotowan� przez ciebie mieszank�: \033[0;33m\nA - dmuchanie s�omk� tak aby byly b�belki\nB - rozszczep atomowy\nC - mieszanie przy stopniowym podrzegwaniu",
    "\nTeraz czas �eby� prawid�owo obrobi� przygotowan� przez ciebie mieszank�: \033[0;33m\nA - dmuchanie s�omk� tak aby byly b�belki\nB - rozszczep atomowy\nC - mieszanie przy stopniowym podrzegwaniu",
    "\nStrasznie rozbola� ci� brzuch. Zwijasz si� wrzecz. Ju� wiesz, �e nie przygotowa�e� dobrego napoju.\033[0;33m\nA - z trudem si� podnosisz i rozpoczynasz gotowanie jeszcze raz\nB - wracasz na rozdro�e, mo�e zapomnia�e� uda� si� gdzie�, gdzie mig�bys dowiedzie� si� wi�cej o koniaku\nC - sfrustrowany, poddajesz si�, widocznie nie nadajesz si� do tego\033[0m",
    "\nWybierasz deklamacj� poematu. Widownia szaleje, sw�j wyst�p ko�czysz:\033[0;33m\nA - k�aniasz si� z godno�ci�\nB - ko�czysz deklamacj� dono�nym zar�ni�ciem\nC - wystukujesz kopytami ostatni� linijk� kodem morsa\033[0m",
    "\nPorwany d�wi�kami muzyki, zachowujeszs si� zbyt pewnie, wykonujesz figury, kt�rych nigdy nie pr�bowa�e�. Niestety niefortunnie upadasz i �amiesz nog�. Zostajesz unieruchomiony na kilka miesi�cy. W tym stanie twoja misja zostaje przerwana",
    "\nPoddajesz si�, nie do��, �e naprawd� boli ci� brzuch, to jeszcze zawiod�e� w swojej misji. Masz wra�enie, �e twoje �ycie ju� nie ma sensu. Nagle wn�trzno�ci ci si� wywijaj� na drug� stron�\nNatychmiastowo udajesz si� do szpitala na p�ukanie �o��dka i porzucasz swoj� misj� na zawsze",
    "\nPo�wi�casz swoje �ycie bronieniu innym. Masz wiele przyg�d na kt�re niestety nie ma miejsca w tej powie�ci. Jeste� zbyt zaj�ty by kiedykolwiek wr�ci� do do swojej m�odzie�czej misji. Mimo to prze�ywasz dobre �ycie",
    "\nWytwarzasz nap�j idealny. Po skosztowaniu go doznajesz ekstazy a �wiat wiruje ci przed oczami. Wiesz, �e to jest to, czego szuka�e�",
    "\nOsi�gn��e� sukces, ale nagle widzisz obezw�adniaj�cy blask. Przed tob� pojawia si� dziwna kreatura, nieprzypominaj�ca nic ludzkiego. Wyci�ga do ciebie r�k� i s�yszysz przenikaj�cy ci� do g�ebi g�os. \033[1;95m\n%s Wytworzy�e� co� do czego ziemskie istoty nigdy nie powinny doj��.\nJeste�my pod wra�eniem twoich umiej�tno�ci, ale niestety musisz p�j�� z nami. Ta wiedza jest zbyt pot�na. Ten nap�j mo�e zdestabilizowa� wszystko co wy tu zbudowali�cie. Nam jednak zale�y by�cie rozwin�li si� do cywilizacji chocia�by typu II, by�my mogli dalej razem pracowa�. \033[0m\nUdajesz si� wi�c z nimi. Widzisz rzeczy jakie si� nie �ni�y prorokom. Wiedziesz dobre �ycie pe�ne przyg�d, na kt�re nie ma miejsca w tej opowie�ci",
    "\nNap�j wybucha ci w twarz. Umierasz na miejscu",
    "\nNiedobry nap�j", //�mier�?
    "\nPo podpisanej umowie udajesz si� razem z pani� agentk�. Wiedziesz karier� pe�n� sukcesu",
    "\nPozostajesz w ��cznej. Pokocha�e� to miejsce i jego mieszka�c�w. Po�wi�casz swoje �ycie burmistrzowaniu z sukcesem ",
    "\nUmierasz na miejscu"


    };


    char tablica_zwyciezcow[5][100] = { "Mim, kt�ry wspi�� si� do sufitu na wyobra�onej linie","pi�ciolatka ta�cz�ca breakdance", "meksykanin �piewaj�cy arie operow�", "staruszka ta�cz�ca na szarfie", "kucharz gotuj�cy ros� w 30 sekund" };


    printf("\tKO� W POSZUKIWANIU KONIAKU\n");
    printf("\nJak ci na imi�, graczu? ");
    scanf("%s", imie);
    printf("\nDobrze wi�c, \033[0;31m%s, \033[0mjeste� koniem.", imie);
    printf("\nTwoj� najwi�ksz� ambicj�, marzeniem i misj� jest wytworzenie najlepszego \033[0;92mkoniaku\033[0m na �wiecie.");
    printf("\nMapa wygl�da tak:");
    printf("\n\t\033[0;32m-------------------------------------\n\t\033[0;32m-----------\033[0;31mX\033[0;32m-------------------------\n\t\033[0;32m-------------------------------------\n\t\033[0;32m--------------------\033[1;33mC\033[0;32m----------------\n\t\033[0;32m-------------------------------------\n\t\033[0;32m-------------------------------------\n\t\033[0;32m-------------------------------------\n\t\033[0;32m-------------------------------------\n\t\033[0;32m-----------------------------\033[1;33mB\033[0;32m-------\n\t\033[0;32m-------------------------------------\n\t\033[0;32m--------------\033[1;33mA\033[0;32m----------------------\n\t\033[0;32m-------------------------------------\n\t\033[0;32m-------\033[1;35mW\033[0;32m-----------------------------\n\t\033[0;32m-------------------------------------\n\t\033[0;32m-------------------------------------\033[0m");
    printf("\v\nX - dom, mo�esz do niego doj�� tylko z wsi C, dlatego warto by� dobrze przygotowanym przed powrotem do domu");
    printf("\nA,B,C to s� wsi po kt�rych b�dziesz podr�owa�.\nCzym jest W dowiesz si� w swoim czasie");
    printf("\nWybieraj m�drze, i powodzenia ;)");



    while (i <= 53) {

        printf("\n%s", tablica_tekstow[i]);

        //wychwycenie stacji na kt�rych dochodzi do elementu losowego i rozegranie ich
        if (i == 2 || i == 31 || i == 40 || i == 37) {

            if (i == 2) {                 //RNG WALKA
                scanf(" %c", &rng_wybor);
                if (rng_wybor == 'a' || rng_wybor == 'b' || rng_wybor == 'A' || rng_wybor == 'B') {
                    int tmp = rng(0, 9);
                    if (tmp > 5) {
                        i = 4;
                    }
                    else { i = 5; }
                }
                else if (rng_wybor == 'c' || rng_wybor == 'C') {
                    i = 3;
                }
                else {
                    printf("Nieprawid�owy wybor. Mo�esz u�ywa� tylko: \033[0;31mA, a, B, b, C, c \033[0m");
                    i = 2;
                }
            }



            //walka wybor dobry


            else if (i == 31) {         //RNG MAM TALENT
                printf("\nPubliczno�� zadecydowa�a\n");
                int tmp2 = rng(0, 9);
                if (tmp2 < 5) {
                    printf("\nprzegrywasz");
                    i = 37;
                }
                else {
                    printf("\nwygrywasz");
                    i = 32;
                }
            }
            else if (i == 40) {             //RNG zlamanie nogi
                int tmp3 = rng(0, 9);
                if (tmp3 >= 7) {
                    printf("\nPo�lizgujesz si� i upadasz!");
                    i = 54;
                }
                else {
                    printf("\nW ostatniej chwili �apiesz r�wnowag�");
                    i = 31;
                }
            }
            else if (i = 37) {        //RNG zwyciezca mam talent
                int tmp4 = rng(0, 4);
                printf("\nWygrywa %s!!", tablica_zwyciezcow[tmp4]);
                i = 33;
            }

        }


        else {

            printf("\n\033[0mwybierz a/b/c: ");
            scanf(" %c", &wybor);

            if (wybor == 'a' || wybor == 'b' || wybor == 'c' || wybor == 'A' || wybor == 'B' || wybor == 'C') {



                switch (wybor) {
                case 'a':
                    k = matryca_przejsc[i][1];      //k zczytuje kolejn� stacj� z wyboru gracza
                    i = k;                            //i zmienia si� na k - kolejn� stacj�
                    break;

                case 'A':
                    k = matryca_przejsc[i][1];
                    i = k;
                    break;

                case 'b':
                    k = matryca_przejsc[i][2];
                    i = k;
                    break;

                case 'B':
                    k = matryca_przejsc[i][2];
                    i = k;
                    break;

                case 'c':
                    k = matryca_przejsc[i][3];
                    i = k;
                    break;

                case 'C':
                    k = matryca_przejsc[i][3];
                    i = k;
                    break;

                }

            }
            else {
                printf("Nieprawid�owy wybor. Mo�esz u�ywa� tylko: \033[0;31mA, a, B, b, C, c \033[0m");
            }
        }

    }


    printf("\n%s", tablica_tekstow[i]);
    printf("\n\v\t===========================\v\n\t\tKONIEC GRY\n\t\v===========================");




    return 0;
}


