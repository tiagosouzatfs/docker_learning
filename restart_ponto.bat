echo novo terminal para reinício do ponto
whoami
TASKLIST /FI "IMAGENAME eq java.exe"
cd C:/Windows/system32
TASKKILL /F /IM java.exe /T
cd C:/Users/PONTO - GCTI/Downloads
java -jar -Dspring.profiles.active=prod leitor-0.0.1-SNAPSHOT.jar
pause