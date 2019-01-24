# ReliableUdpMulticast

# Przykład przetestowania
1. W terminalu uruchamiamy polecenie `nc -lu 4000`
2. W projekcie trzeba umieścić kod w jakimś miejscu, do którego program "dotrze" i kod zostanie wykonany:

`UdpClient *udpClient = new UdpClient(AF_INET, SOCK_DGRAM, IPPROTO_UDP, "127.0.0.1", "3700");`

 `udpClient->sendToIp("127.0.0.1", "4000", "kurczak");`
 
 `delete udpClient;`


TTD:

- [x] Wysłanie pakietu na adres multicastowy, dla którego ma nastąpić odpowiedź członków adresu multicast + podanie sposobu testowania przy użyciu zewnętrznych narzędzi
- [ ] Czekanie na pakiet zwrotny z informacją o adresie IP który przyjdzie od członka adresu multicast + podanie sposobu testowania przy użyciu zewnętrznych narzędzi
- [ ] Stworzenie oczekiwania na wszystkich odbiorców i zakwalifikowanie ich do transmisji - określenie maksymalnego czasu oczekiwania, zebranie ich np. do tablicy
- [x] Podział danych na pakiety i wysłanie ich do odbiorców
- [ ] Funkcjonalność dosyłania pojedynczego pakietu do odbiorcy, na razie nie zależnie, od tego, czy otrzymał pakiet, czy nie
- [x] Zapoznać się z mechanizmem okna przesuwnego i wybiórczych potwierdzeń (selective acks) z TCP i zastanowienie się, jak można to zrealizować w projekcie
- [ ] Realizacja otrzymywania potwierdzeń - do doprecyzowania po kroku powyższym
- [ ] Realizacja dosyłania na bazie braku potwierdzenia
- [ ] W razie potrzeby, uzupełnienie pakietów o informację o liczbie, kolejności, itp.

----------
- [x] Upload pliku
- [x] Wysyłanie wybranego pliku
- [ ] Zebranie otrzymanych pakietów do jednego pliku
- [ ] Możliwość pobrania otrzymanego pliku
- [ ] ...
----------
Przed oddaniem:

- [ ] Projekt buduje się automatycznie (np. make)
- [ ] Programy mają się kompilować bez ostrzeżeń (z flagą kompilatora -Wall)
- [ ] Przetestowanie kodu analizatorami statycznymi: splint, cppcheck, clang
- [ ] Przetestowanie wykonania analizatorem dynamicznym: valgrind
