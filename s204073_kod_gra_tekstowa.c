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

    int n, k = 0, i = 0; // i - obecne po³o¿enie(kolumna1); k - zczytuje i przekazuje i po³o¿enie wynikaj¹cr z wyboru;
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

    // tablica_tekstow - zawiera opisy kazdej stacji (stacja to matryca_przejsc[0][i]) i wyswietla odpowiedni tekst i wybory; zawiera te¿ kilka dodatkowych miejsc na ewnetualne rozwiniecie gry
    char tablica_tekstow[69][1000] =
    { "Rozpoczynasz swoj¹ wymarzon¹ podró¿. Zdecyduj siê gdzie chcesz siê udaæ najpierw\033[0;33m\nA - Tupad³y \nB - £êczna\nC - Samoklêski\033[0m",
    "\nUdajesz siê do wsi Tupad³y.\nNagle widisz jak dwóch typków atakuje samotn¹ staruszkê. Wyrywaj¹ jej torebkê a ona nie ma jak siê broniæ. \033[0;33m\nA - bronisz j¹\nB - uciekasz\nC - korzystasz na tym\033[0m",
    "\nPodbiegasz rozjuszony bezczelnoœci¹ napastników. Jest ich dwóch, wiêc wiesz, ¿e nie bêdzie ³atwo mimo tego zadajesz cios! \033[0;31m\nA - cios z lewej \nB - cios z prawej\nC - kopniak tylnymi kopytami \033[0m",
    "\nPowalasz swoich przeciwników. Owa staruszka mówi do ciebie \n\033[0;34mNawet nie wiesz ile ci zawdziêczam m³ody cz³owieku\n\033[0mPrzyjrza³a ci siê dok³adniej i doda³a\n\033[0;34mA raczej koniu\nNieistotne z reszt¹, nie wiem gdzie ciê droga poniesie ale przyjmij dwa ostrze¿enia od starszej doœwiadczonej kobiety\n\033[1;92m\v1)w pobli¿u znajduje siê niejaki Wilczy Szaniec, pod ¿adnym pozorem tam nie idŸ. Nikt z tamt¹d jeszcze nie wróci³.\n2) wystrzegaj siê niejakiej koñskiej trawki. Nawet jeœli by ciê rówieœnicy nak³aniali.\033[0m\n Ruszasz wiêc dalej, stajesz na rozdro¿u:\033[0;33m\nA - Wilczy Szaniec \nB - £êczna \nC - Samoklêski\033[0m",
    "\nTwój cios okaza³ siê nienajlepszy. Musisz im do³o¿yæ\033[0;33m\nA - kopniak w nogê \nB - uderzenie ogonem niczym biczem\nC - uderzenie g³ow¹ jak to tylko konie potrafi¹\033[0m",
    "\nTwój cios okaza³ siê tragicznie s³aby. Musisz siê bardziej wysiliæ by pokonaæ swoich przeciwników \033[0;33m\nA - kopniak w nogê \nB - uderzenie ogonem niczym biczem\nC - uderzenie g³ow¹ jak to tylko konie potrafi¹\033[0m",
    "\nJu¿ lepiej! Ale jeszcze przeciwnicy siê trzymaj¹ na nogach (co jest niepo¿¹dane), musisz u¿yæ najbardziej wyszukanych metod by ich ostatecznie pokonaæ \033[0;33m\nA - nadepniêcie na but\nB - pogilgotanie\nC - opowiedzenie najsuchszego suchara jaki œwiat s³ysza³\033[0m",
    "\nUciekasz. Wolisz siê nie mieszaæ. Szwêdasz siê po wsi targany wyrzutami sumienia, w koñcu trafiasz na targ. Widzisz tam m³odego mê¿czyznê, w którym rozpoznajesz jednego z tych, co przed chwil¹ pobili staruszkê. \033[0;33m\nA - rozmawiasz z nim i tak\nB - zg³aszasz go na policjê\nC - odchodzisz i opuszczasz miasto\033[0m",
    "\nPodchodzisz do owego mê¿czyzny i t³umaczysz swój cel podró¿y\n\033[0;34mSzukasz czegoœ do koniaku? S³uchaj bratku, dorzuæ tam nieco koñskiej trawki, po tym to dopiero jest ODLOT hehe\033[0m\nOpuszczasz wiêc wieœ\033[0;33m\nA - Wilczy Szaniec \nB - £êczna \nC - Samoklêski\033[0m",
    "\nNatychmiast przyt³oczony poczuciem winy, udajesz siê, by zg³osiæ, to co widzia³eœ na komisariat\nPolicjant mówi\n\033[0;34mNaprawdê powinieneœ jej pomóc, babcia Brygida to wspania³a kobieta. No nic, widzê, ¿e jesteœ podró¿nym.\nW pobli¿u znajduje siê niejaki Wilczy Szaniec, pod ¿adnym pozorem tam nie idŸ. Nikt z tamt¹d jeszcze nie wróci³.\nOpuszczasz wiêc wieœ\033[0;33m\nA - Wilczy Szaniec \nB - £êczna \nC - Samoklêski\033[0m",
    "\nOpuszczasz miasto i widzisz trzy znaki: \033[0;33m\nA - Wilczy Szaniec \nB - £êczna \nC - Samoklêski\033[0m",
    "\nWyrzekasz siê swojego w¹tpliwego cz³owieczeñstwa.\nPodbiegasz do szarpi¹cej siê trójki. Wyrywasz torebkê i uciekasz na œlepo z wioski. Dobiegasz na skrzy¿owanie i widzisz ukryt¹ dró¿kê do Wilczego Szañca\nMyœlisz sobie:\033[0;36m\nTo chyba to, tam nikt mnie nie znajdzie!\033[0;33m\nA - Wilczy Szaniec \nB - £êczna \nC - Samoklêski\033[0m",
    "\nTrafiasz do £êcznej.\nWidzisz miasto a¿ kipi. Protest trwa. Nie rozumiesz co siê dzieje, ale jesteœ zaintrygowany. Chcesz siê czegoœ dowiedzieæ, gdzie siê udajesz?\033[0;33m\nA - Urz¹d miasta\nB - Targ\nC - Karczma\033[0m ",
    "\nWchodzisz do urzêdu. Podchodzisz do biurka i uœmiechasz siê do siedz¹cej za nim sekretarki burmistrza.\n Zanim jednak zd¹¿ysz siê wys³owiæ, s³yszysz tylko:\033[0;34mTO NIE INFORMACJA TURYSTYCZNA\nBURMISTRZ JEST TERAZ BARDZO ZAJÊTY\nPROSZÊ OPUŒCIÆ URZ¥D\033[0m\nNie masz zbytnio wyboru. \033[0;33m\nA - wychodzisz z miasta\nB - udajesz siê na targ\nC - idziesz do karczmy\033[0m ",
    "\nZnajdujesz siê na rozdro¿u, zdecyduj, gdzie chcesz siê teraz siê udaæ: \033[0;33m\nA - Tupad³y \nB - £êczna \nC - Samoklêski\033[0m",
    "\nIdziesz na targ. Tam podchodzisz do najbardziej przyjaŸnie wygl¹daj¹cego sprzedawcy i zagadujesz \n\033[0;36mS³uchaj jestem przyjezdny, a widzê,¿e macie tu niez³y raban, mo¿esz mi wyjaœniæ co siê w³aœciwie dzieje\033[0;34m\nWitam Ciê w £êcznej, chcia³bym, ale nie mam czasu z Tob¹ po rozmawiaæ, jeœli chcesz informacji udaj siê do karczmy.\033[0m\n Gdzie siê udajesz? \033[0;33m\nA - idziesz do urz¹du\nB - wychodzisz z miasta\nC - udajesz siê do karczmy\033[0m",
    "\nWchodzisz do karczmy. Podchodzisz do lady i zagajasz stoj¹cego za barem m³odego ch³opaka\n\033[0;36mNiez³y raban tu macie. Zawsze wiedzia³em, ¿e £êczna ma zaciêcie polityczne odk¹d by³ tu prezydent kiedyœ.\n\033[0;34mAno, obecny burmistrz jest tragiczny, kradnie nasze pieni¹dze,a nasza wioska ma problem by go przepêdziæ i wygraæ z nim wybory. \033[0mS³ysz¹c to rozwa¿asz ró¿ne mo¿liwoœci: \033[0;33m\nA - startujesz na burmistrza\nB -\033[0;36mPrzykro mi to s³yszeæ, chcia³bym pomóc, ale mam misjê \033[0;33m\nC - \033[0;36mHaha, sami so tego doprowadziliœcie. Na mmnie ju¿ czas\033[0m",
    "\n\033[0;34mMasz dobre serce, szkoda, ¿e nie mo¿esz nam pomóc, jedynie co ci mogê powiedzieæ, to ¿e moja babcia zwyk³a mówiæ, ¿e \033[1;92mprzy wytwarzaniu koniaku najlepiej go rozszczepiæ atomowo dla pe³ni smaku. \n\033[0;34m Trzymaj siê \n\033[0mPodnosisz siê z miejsca i kierujesz do wyjœcia:\033[0;33m\nA - idziesz do urzêdu\nB - idziesz na targ\nC - opuszczasz miasto\033[0m ",
    "\n\033[0;36mWystartujê! Nie mogê was tak z tym zostawiæ!\n\033[0;34mWow to naprawdê szlachetne z twojej strony, jeœli jednak bêdziesz chcia³ wróciæ do swojej misji - pamiêtaj s³owa mojej babci - \033[1;92mnajlepszy na wydobycie smaku z koniaku jest rozszczep atomowy\033[0m \nZmotywowany tym decydujesz siê na kampaniê, na czym chcesz siê skupiæ?: \033[0;33m\nA - na komunikacji miejskiej, stworzenie rezerwatu dla dzików - tego tak zas³u¿onego gatunku dla tego miasta i przywrócenia miasta do stanu œwietnoœci\nB - na wzroœcie gospodarczym i wypromowanie miasta na terenie ogólnopolskim\nC - zestresowany, rezygnujesz z pomys³u i opuszczasz miasto\033[0m ",
    "\nNiestety, obrana przez ciebie kampania, nie przekona³a £êcznianów i £êcznianki. Przegra³eœ wybory. W £êcznej znów zapanowa³a dyktatura. Przypominasz se jednak o swojej misji i bogatszy o wiedzê i doœwiadczenie ruszasz w dalsz¹ podró¿: \033[0;33m\nA - Tupad³y \nB - £êczna \nC - Samoklêski\033[0m",
    "\nPrzeprowadzasz œwiêtn¹ kampaniê, zjednaj¹c sobie wszystkich £êcznianów i £êcznianki. Wygrywasz wybory. \n Stajesz jednak przed powa¿nym wyborem:\033[0;33m\nA - poœwiêcasz swoje ¿ycie burmistrzowaniu \nB - pracujesz ciê¿ko kilka lat jako burmistrz ale ostatecznie przypominasz se o swojej misji\nC - abdykujesz i uciekasz\033[0m ",
    "\nNaprawdê przywi¹za³eœ siê do £êcznej, œwiadomy jesteœ jednak, ¿e du¿o dla nich zrobi³eœ, wybudowa³eœ linie tramwajowe, zaj¹³eœ siê tematem dzików, przywróci³eœ nadziejê w sercach £êcznian, a wiedz¹c, ¿e nie jesteœ stworzony na burmistrza, ruszasz dalej w œwiat: \033[0;33m\nA - Tupad³y \nB - opuœæ miasto \nC - Samoklêski\033[0m",
    "\nUdajesz siê do wsi Samoklêski. Od razu po wejœciu na obszar wsi czujesz zbiorowe podniecenie i atmosferê oczekiwania. Nie musisz d³ugo czekaæ, by dowiedzieæ siê o co chodzi, plakaty og³¹szaj¹ce miêdzywsiowy konkurs talentów wisz¹ dos³owmnie WSZÊDZIE, z rozbawieniem dostrzegasz nawet jakiegoœ pêdrêka biegn¹cego z kartk¹ przyklejon¹ do pleców. \033[0;33m\nA - opuszczasz miasto\nB - idziesz dalej\nC - bierzesz udzia³\033[0m",
    "\nIdziesz i idziesz po wsi, ale ca³a spo³ecznoœæ, powiêkszona o przyjezdznych ¿yje owym konkursem talentów: \033[0;33m\nA - opuszczasz miasto\nB - idziesz do domu\nC - bierzesz udzia³\033[0m",
    "\nZdecydowa³eœ siê wzi¹æ udzia³  w konkursie. Musisz siê zastanowiæ nad swoimi talentami. W jakich kategoriach jesteœ rozwiniêty?:\033[0;33m\nA - muzycznych\nB - intelektualnych\nC - ruchowych\033[0m ",
    "\nZdolnoœci muzyczne. Wybierz jaki wystêp zaprezentujesz: \033[0;33m\nA - taniec\nB - gra na perkusji\nC - granie na kieliszkach z wod¹\033[0m",
    "\nZdolnoœci ruchowe czy te¿ kinetyczne. Wybierz jaki wystêp zaprezentujesz:\033[0;33m\nA - hobby horsing\nB - akrobacje w stroju spidermana\nC - bieg przez p³otki\033[0m",
    "\n\nZdolnoœci intelektualne. Wybierz jaki wystêp zaprezentujesz: \033[0;33m\nA - recytacja rozwiniêcia liczby Pi\nB - deklamacja poematu\nC - wystêp magiczny/iluzjonistyczny\033[0m",
    "\nPróbujesz ponownie swoich si³. Rozwa¿asz ponownie swoje mocne i s³abe strony. W jakich kategoriach jesteœ rozwiniêty?:\033[0;33m\nA - muzycznych\nB - intelektualnych\nC - ruchowych\033[0m ",
    "\nWidownia nie pochwali³a twojego wystêpu, wszêdzie by³o s³ychaæ buczenie niezadowolonej widowni, nie wiesz jak sobie z tym poradziæ \033[0;33m\nA - uciekasz w smutku z miasta\nB - udajesz siê z innymi przegranymi na herbatê na pocieszenie\nC - próbujesz ponownie\033[0m",
    "\nWybierasz siê z innymi przegranymi na herbatê, wœród przyjemnych rozmów dowiadujesz siê, ¿e regionalnym specyfikiem u¿ywanym w wytwarzaniu koniaku jest \033[1;92mpodejŸrzon ksiê¿ycowy\033[0mPocieszony i wzbogacony o now¹ wiedzê stajesz przed decyzj¹: \033[0;33m\nA - opuszczasz miasto\nB - idziesz do domu\nC - wracasz na konkurs, ponownie spróbowaæ swoich si³\033[0m ",
    "\nWykonujesz wspania³y wystêp. Dostajesz siê do fina³u, a o twojej potencjalnej wygranej zdecyduje teraz widownia. Z niecierpliwoœci¹ czekasz na wynik...",
    "\nWiêkszoœci¹ g³osów widownii wygrywasz!!!! Otrzymujesz nagrodê pieniê¿n¹, a burmistrz Samoklêski s³ysz¹c o twojej misji przekazuje ci tajny lokalny sk³adnik -\033[1;92mpodejŸrzon ksiê¿ycowy\033[0m. \033[0;33m\nA - oblewasz szampana\nB - podskakujesz, rz¿¹c radoœnie\nC - przyt³oczony presj¹ uciekasz\033[0m ",
    "\nNiestety nie ty wygra³eœ fina³. \033[0;33m\nA - nie poddajesz siê, próbujesz ponownie\nB - opuszczasz miasto\nC - idziesz do domu\033[0m",
    "\nPublicznoœæ domaga siê bisu.\nDooko³a ciebie s³yszysz tylko \033[0;34mBIS BIS BIS wiêcej! wiêcej!! TAK!!! NIECH ON TO ZROBI JESZCZE RAZ!!!!!\033[0;33m\nA - wykonujesz swój wystêp ponownie\nB - dziêkujesz zgromadzonym i wyg³¹szasz mowê\nC - k³aniasz siê i po angielsku schodzisz ze sceny\033[0m",
    "\nWszyscy s¹ pod wra¿eniem, chc¹ wiêcej i wiêcej. Podchodzi do ciebie elegancko ubrana kobieta \033[0;34mWow, to naprawdê twój ¿ywio³, powinieneœ siê na tym skupiæ, jako swój zawód.\nTak siê sk³ada, ¿e jestem agentk¹ firmy bior¹cej pod swoje skrzyd³a talenty takie jak ty.\033[0m\nNagle ona wyci¹ga zza plecy gotow¹ umowê \033[0;33m\nA - podpisujesz z ni¹ umowê, przprzyjmuj¹c swój talent na swój zawód\nB - \033[0;36mDziêkujê ci bardzo, ale mam misjê, na któej mi bardzo zale¿y, niestety muszê odrzuciæ twoj¹ propozycjê \033[0;33m\nC - odchodzisz i opuszczasz miasto\033[0m",
    "\nOtrzymujesz z³oty przycisk. Widownia szaleje. Wszêdzie ludzie klaszcz¹ i tupi¹. Burmistrz wrêcza ci kompedium wiedzy o koniaku, z którego dowiaduejsz siê, ¿e ¿eby otrzymaæ najlepszy na œwiecie koaniak nale¿y\033[1;92m\n1)dodaæ do niego podejŸrzon ksiê¿ycowy\n2)rozszczepiæ go atomowo\n3)wystrzegaæ siê z³udnej koñskiej trawki\033[0m \033[0;33m\nA - wychodzisz na scenê z zamiarem podziekowania widzom\nB - dziêkujesz zgromadzony, ale informujesz, ¿e masz misjê i pozyskawszy potrzebn¹ wiedzê niezzw³ocznie udajesz siê do domu podj¹æ siê ugotowania najlepszego koniaku na œwiecie\nC - opuszczasz miasto\033[0m ",
    "\nNa scenê wchodzi zwyciêzca",
    "\ntmp",
    "\ntmp",
    "\nTañczysz ale boli ciê noga",
    "\nZostajesz pajêkokoniem, bohaterem. Czujesz w sobie niezwyk³¹ moc i potrzebê obrony s³abszych.\033[0;33m\nA - poddajesz siê temu obecw³adniaj¹cemu uczuciu i decydujesz siê porzuciæ wszytsko i pójœæ œladami spidermana\nB - ignorujesz wo³anie i spokojnie wykonujesz swój wystêp\nC - zmieniasz dyscypline\033[0m",
    "\nPo d³ugiej podró¿y, wracasz do domu. Nadszed³ czas na refleksjê.\nCzy uda³o ci siê udaæ, wszêdzie, gdzie chcia³eœ?\033[0;33m\nA - Jeszcze nie wszystko uda³o mi siê zrobiæ. Nie jestem gotowy\033[0;36m \n\033[0;33mWracasz na rozdro¿e\nB - rozpoczynasz wyczekiwane gotowanie\nC - tkniêty chandr¹ podchodzisz do mapy wisz¹cej na œcianie\033[0m",
    "\nWidzisz wszystkie miejsca do których chcia³eœ siê udaæ. Do których podró¿ planowa³eœ tygodniami. \033[0;33m\nA -wracasz na rozdro¿e\nB - dostrzegasz Wilczy Szaniec, wczeœniej przez ciebie nie odwiedzony, i wyruszasz tam bez namys³u\nC - patrzysz z sadysfakcj¹ na to, co dokona³eœ i rozpoczynasz gotowanie\033[0m",
    "\nUzbrojony w zebran¹ podczas podró¿y wiedzê, rozpoczynasz gotowanie. Do przygotowanego uprzednio naparu wrzucasz pierwszy skladnik\033[0;33m\nA - koñska trawka\nB - miêta\nC - liœæ z drzewa ksiê¿ycowego\033[0m",
    "\nWrzucasz drugi sk³adnik: \033[0;33m\nA - podejŸrzon ksiê¿ycowy\nB - sza³wia\nC - herbata z dzikiego zachodu\033[0m",
    "\nWybierasz posmak napoju, co wrzucasz: \033[0;33m\nA - resztki meteorytu znalezione przez twojego dziadka w ogródku\nB - mieszanka cytrusowa\nC - coca cola\033[0m",
    "\nTeraz czas ¿ebyœ prawid³owo obrobi³ przygotowan¹ przez ciebie mieszankê: \033[0;33m\nA - dmuchanie s³omk¹ tak aby byly b¹belki\nB - rozszczep atomowy\nC - mieszanie przy stopniowym podrzegwaniu\033[0m",
    "\nTeraz czas ¿ebyœ prawid³owo obrobi³ przygotowan¹ przez ciebie mieszankê: \033[0;33m\nA - dmuchanie s³omk¹ tak aby byly b¹belki\nB - rozszczep atomowy\nC - mieszanie przy stopniowym podrzegwaniu",
    "\nWrzucasz drugi sk³adnik: \033[0;33m\nA - podejŸrzon ksiê¿ycowy\nB - sza³wia\nC - herbata z dzikiego zachodu",
    "\nTeraz czas ¿ebyœ prawid³owo obrobi³ przygotowan¹ przez ciebie mieszankê: \033[0;33m\nA - dmuchanie s³omk¹ tak aby byly b¹belki\nB - rozszczep atomowy\nC - mieszanie przy stopniowym podrzegwaniu",
    "\nTeraz czas ¿ebyœ prawid³owo obrobi³ przygotowan¹ przez ciebie mieszankê: \033[0;33m\nA - dmuchanie s³omk¹ tak aby byly b¹belki\nB - rozszczep atomowy\nC - mieszanie przy stopniowym podrzegwaniu",
    "\nStrasznie rozbola³ ciê brzuch. Zwijasz siê wrzecz. Ju¿ wiesz, ¿e nie przygotowa³eœ dobrego napoju.\033[0;33m\nA - z trudem siê podnosisz i rozpoczynasz gotowanie jeszcze raz\nB - wracasz na rozdro¿e, mo¿e zapomnia³eœ udaæ siê gdzieœ, gdzie mig³bys dowiedzieæ siê wiêcej o koniaku\nC - sfrustrowany, poddajesz siê, widocznie nie nadajesz siê do tego\033[0m",
    "\nWybierasz deklamacjê poematu. Widownia szaleje, swój wystêp koñczysz:\033[0;33m\nA - k³aniasz siê z godnoœci¹\nB - koñczysz deklamacjê donoœnym zar¿niêciem\nC - wystukujesz kopytami ostatni¹ linijkê kodem morsa\033[0m",
    "\nPorwany dŸwiêkami muzyki, zachowujeszs siê zbyt pewnie, wykonujesz figury, których nigdy nie próbowa³eœ. Niestety niefortunnie upadasz i ³amiesz nogê. Zostajesz unieruchomiony na kilka miesiêcy. W tym stanie twoja misja zostaje przerwana",
    "\nPoddajesz siê, nie doœæ, ¿e naprawdê boli ciê brzuch, to jeszcze zawiod³eœ w swojej misji. Masz wra¿enie, ¿e twoje ¿ycie ju¿ nie ma sensu. Nagle wnêtrznoœci ci siê wywijaj¹ na drug¹ stronê\nNatychmiastowo udajesz siê do szpitala na p³ukanie ¿o³¹dka i porzucasz swoj¹ misjê na zawsze",
    "\nPoœwiêcasz swoje ¿ycie bronieniu innym. Masz wiele przygód na które niestety nie ma miejsca w tej powieœci. Jesteœ zbyt zajêty by kiedykolwiek wróciæ do do swojej m³odzieñczej misji. Mimo to prze¿ywasz dobre ¿ycie",
    "\nWytwarzasz napój idealny. Po skosztowaniu go doznajesz ekstazy a œwiat wiruje ci przed oczami. Wiesz, ¿e to jest to, czego szuka³eœ",
    "\nOsi¹gn¹³eœ sukces, ale nagle widzisz obezw³adniaj¹cy blask. Przed tob¹ pojawia siê dziwna kreatura, nieprzypominaj¹ca nic ludzkiego. Wyci¹ga do ciebie rêkê i s³yszysz przenikaj¹cy ciê do g³ebi g³os. \033[1;95m\n%s Wytworzy³eœ coœ do czego ziemskie istoty nigdy nie powinny dojœæ.\nJesteœmy pod wra¿eniem twoich umiejêtnoœci, ale niestety musisz pójœæ z nami. Ta wiedza jest zbyt potê¿na. Ten napój mo¿e zdestabilizowaæ wszystko co wy tu zbudowaliœcie. Nam jednak zale¿y byœcie rozwinêli siê do cywilizacji chocia¿by typu II, byœmy mogli dalej razem pracowaæ. \033[0m\nUdajesz siê wiêc z nimi. Widzisz rzeczy jakie siê nie œni³y prorokom. Wiedziesz dobre ¿ycie pe³ne przygód, na które nie ma miejsca w tej opowieœci",
    "\nNapój wybucha ci w twarz. Umierasz na miejscu",
    "\nNiedobry napój", //œmieræ?
    "\nPo podpisanej umowie udajesz siê razem z pani¹ agentk¹. Wiedziesz karierê pe³n¹ sukcesu",
    "\nPozostajesz w £êcznej. Pokocha³eœ to miejsce i jego mieszkañców. Poœwiêcasz swoje ¿ycie burmistrzowaniu z sukcesem ",
    "\nUmierasz na miejscu"


    };


    char tablica_zwyciezcow[5][100] = { "Mim, który wspi¹³ siê do sufitu na wyobra¿onej linie","piêciolatka tañcz¹ca breakdance", "meksykanin œpiewaj¹cy arie operow¹", "staruszka tañcz¹ca na szarfie", "kucharz gotuj¹cy rosó³ w 30 sekund" };


    printf("\tKOÑ W POSZUKIWANIU KONIAKU\n");
    printf("\nJak ci na imiê, graczu? ");
    scanf("%s", imie);
    printf("\nDobrze wiêc, \033[0;31m%s, \033[0mjesteœ koniem.", imie);
    printf("\nTwoj¹ najwiêksz¹ ambicj¹, marzeniem i misj¹ jest wytworzenie najlepszego \033[0;92mkoniaku\033[0m na œwiecie.");
    printf("\nMapa wygl¹da tak:");
    printf("\n\t\033[0;32m-------------------------------------\n\t\033[0;32m-----------\033[0;31mX\033[0;32m-------------------------\n\t\033[0;32m-------------------------------------\n\t\033[0;32m--------------------\033[1;33mC\033[0;32m----------------\n\t\033[0;32m-------------------------------------\n\t\033[0;32m-------------------------------------\n\t\033[0;32m-------------------------------------\n\t\033[0;32m-------------------------------------\n\t\033[0;32m-----------------------------\033[1;33mB\033[0;32m-------\n\t\033[0;32m-------------------------------------\n\t\033[0;32m--------------\033[1;33mA\033[0;32m----------------------\n\t\033[0;32m-------------------------------------\n\t\033[0;32m-------\033[1;35mW\033[0;32m-----------------------------\n\t\033[0;32m-------------------------------------\n\t\033[0;32m-------------------------------------\033[0m");
    printf("\v\nX - dom, mo¿esz do niego dojœæ tylko z wsi C, dlatego warto byæ dobrze przygotowanym przed powrotem do domu");
    printf("\nA,B,C to s¹ wsi po których bêdziesz podró¿owaæ.\nCzym jest W dowiesz siê w swoim czasie");
    printf("\nWybieraj m¹drze, i powodzenia ;)");



    while (i <= 53) {

        printf("\n%s", tablica_tekstow[i]);

        //wychwycenie stacji na których dochodzi do elementu losowego i rozegranie ich
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
                    printf("Nieprawid³owy wybor. Mo¿esz u¿ywaæ tylko: \033[0;31mA, a, B, b, C, c \033[0m");
                    i = 2;
                }
            }



            //walka wybor dobry


            else if (i == 31) {         //RNG MAM TALENT
                printf("\nPublicznoœæ zadecydowa³a\n");
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
                    printf("\nPoœlizgujesz siê i upadasz!");
                    i = 54;
                }
                else {
                    printf("\nW ostatniej chwili ³apiesz równowagê");
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
                    k = matryca_przejsc[i][1];      //k zczytuje kolejn¹ stacjê z wyboru gracza
                    i = k;                            //i zmienia siê na k - kolejn¹ stacjê
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
                printf("Nieprawid³owy wybor. Mo¿esz u¿ywaæ tylko: \033[0;31mA, a, B, b, C, c \033[0m");
            }
        }

    }


    printf("\n%s", tablica_tekstow[i]);
    printf("\n\v\t===========================\v\n\t\tKONIEC GRY\n\t\v===========================");




    return 0;
}


