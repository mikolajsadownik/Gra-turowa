# Gra turowa
 Projekt polega na stworzeniu aplikacji konsolowej symulującej grę walki turowej z 
implementacją oddziaływań między przeciwnikami (przykład: system walki w grze Pokemon).
# Opis
Gracz posiada zestaw 6 stworzeń którymi kieruje. Celem gry jest pokonanie wszystkich 
przeciwników stojących na drodze, z jak najmniejszym kosztem dla swojej drużyny.
Aplikacja jest uruchamiana z poziomu linii poleceń. Bazując na 
komendach czytanych z klawiatury, wykonuje odpowiednie zagrania dla postaci.
Rozgrywka dzieli się na co najmniej 4 rundy, przy czym każda runda posiada 
przynajmniej 4 przeciwników. Wszyscy przeciwnicy są losowani z puli stworzeń, z których 
gracz może wybrać swój zespół.
Na początku rozgrywki gracz może wybrać sobie zespół składający się z sześciu stworzeń z
predefiniowanej puli.

Rozgrywka dzielona jest na tury gracz–przeciwnik, gdzie w jednej turze można wykonać 
następujące akcje:
- Użycie umiejętności specjalnej/ataku	
- Wymiana stworzenia
- Ewolucja stworzenia

Po zmniejszeniu statystyki Punkty Życia stworzenia, mdleje ono, i nie można go ponownie 
wykorzystać do końca walki.W momencie pokonania wszystkich przeciwników gra się kończy zwycięstwem gracza.
Każde stworzenie posiada atrybuty definiujące jej zachowania i wpływ na rozgrywkę, w 
atrybuty wlicza się:
- Siła – definiuje, ile obrażeń może zadać stworzenie jednym atakiem;
- Zręczność – definiuje, jaka jest szansa na uniknięcie ataku przeciwnika;
- Punkty Życia – definiuje, ile obrażeń może przyjąć stworzenie zanim zemdleje;
- Moc Specjalna – określa charakterystyki mocy specjalnej dla danego stworzenia oraz 
maksymalną liczbę jej użyć w jednej walce.
- Punkty EXP – ile punktów EXP jest przyznawane za pokonanie przeciwnika.

Każde stworzenie posiada również swój typ (Woda, Ziemia, Powietrze, Ogień, Lód, Stal) które 
wpływają jak dobrze ich ataki wpływają na inne stworzenia. Tabelka oddziaływań znajduje się 
poniżej 

![image](https://user-images.githubusercontent.com/109753404/198529885-d0f9f2ee-ef01-48e2-a749-f8a03107d4f4.png)

Gdzie zielony kolor oznacza zwiększoną efektywność, natomiast żółty kolor oznacza zmniejszoną efektywność.
Każde stworzenie może po uzyskaniu określonej dla niego liczby EXP ewoluować, zwiększając 
swoje atrybuty. Gracz ma możliwość decydowania które dwa atrybuty chce powiększyć w 
stworzeniu.




