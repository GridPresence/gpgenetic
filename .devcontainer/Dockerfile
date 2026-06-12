
FROM ubuntu:26.04 AS devcont
# Non-interactive apt tools behaviour
ENV DEBIAN_FRONTEND=noninteractive

ENV SERVICE_NAME="development"
ENV NEWHOME=/home/$SERVICE_NAME
ENV UID=1234

# Repairing the Ubuntu default shell as bash
RUN rm /bin/sh ; \
    ln -s /bin/bash /bin/sh

# Basic package set
RUN apt-get -y update; apt-get -y upgrade
COPY packages.txt /tmp/packages.txt
RUN xargs apt-get -y install < /tmp/packages.txt

RUN adduser \
    --disabled-password \
    --gecos "" \
    --shell "/bin/bash" \
    --home "$NEWHOME" \
    --uid "$UID" \
    "$SERVICE_NAME"
# Move down onto project root directory
WORKDIR $NEWHOME
# Create host FS mount point
RUN mkdir -p $NEWHOME/work
RUN chown -R $SERVICE_NAME:$SERVICE_NAME $NEWHOME
WORKDIR $NEWHOME/work
# Don't want to run as root
USER $SERVICE_NAME

# CMD ["bash", "dexecute"]
