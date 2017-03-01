FROM debian:8

MAINTAINER <ale-batt@student.42.fr>

RUN apt-get update
RUN apt-get install -y build-essential

ADD . /app
WORKDIR /app

RUN cd /app && make fclean && make

ENTRYPOINT ["/app/ft_ping"]
