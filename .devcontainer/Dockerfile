FROM alwaysproblem/fastdev-u2204:gc-conda

RUN apt update -y && \
    apt-get install -y \
    python3 python3-dev python3-setuptools \
    gcc libtinfo-dev zlib1g-dev \
    build-essential cmake \
    libedit-dev libxml2-dev ninja-build

RUN git config --global --add safe.directory '*' && \
    /root/.local/bin/setup_new_user 1003 1000
