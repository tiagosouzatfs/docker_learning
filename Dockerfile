# Definir uma imagem base
FROM centos:7

# Executar a atualização dos pacotes
RUN yum update -y

# Instalar o squid
RUN  yum install squid -y

# Expor a porta do squid
EXPOSE 3128

# Iniciar o squid
RUN systemctl start squid

# Iniciar o squid junto com o sistema operacional
RUN systemctl enable squid


