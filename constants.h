#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QString>

const QString joinFailure = "Nie znaleziono grupy multicast. Upewnij się, że podany adres jest poprawny.";
const QString joinSuccess = "Grupa multicast rozpoznana!";
const QString fileSendingStart = "Rozpoczęto wysyłanie pliku.";
const QString receiversFound = "Znaleziono odbiorców: %1";
const QString resending = "Ponawianie pakietu dla %1...";
const QString receiverInactive = "Odbiorca %1 nie odpowiada. Odbiorca może nie otrzymać pliku w całości.";
const QString fileSendingSuccess = "Pomyślnie wysłano plik do %1 odbiorców!";
const QString fileReceived = "Odebrano plik. Plik jest dostępny do pobrania.";

const int payloadSize = 508;

#endif // CONSTANTS_H
