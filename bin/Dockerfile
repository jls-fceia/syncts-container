# Construir con podman build -t=localhost/testboost .
# Ejecutar con podman run -d -p 3333:3333 <IMAGE_ID>  
FROM registry.fedoraproject.org/fedora
CMD  dnf install glibc-2.32-1.fc33.x86_64 boost -y
COPY ./syncts /usr/bin/
