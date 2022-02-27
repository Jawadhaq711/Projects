docker build -t cs128final .
docker run -v ${PWD}:/source --name cs128finalenv -d -p 80 -it  cs128final
# -m="12000m"