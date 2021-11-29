FROM tuterm:0.3.0

WORKDIR /collection

RUN rm -rf *
COPY . .

USER root
RUN chown -R user .

USER user
CMD sh
