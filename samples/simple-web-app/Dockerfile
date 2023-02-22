FROM python:3.7.7-slim
RUN mkdir /app
ADD . /app
WORKDIR /app
COPY requirements.txt requirements.txt
RUN pip3 install -r requirements.txt
COPY . .
CMD ["python", "sample-page.py"]