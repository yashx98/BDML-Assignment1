# Steps to Run simple-web-app

(Relevant files under samples/simple-web-app)

1. sudo docker build . -t hello-web
2. sudo docker images
3. sudo docker run -p 8080:8080 hello-web
4. sudo microk8s.enable registry
5. docker save hello-web > hello-web.tar
6. sudo microk8s.ctr image import hello-web.tar
7. sudo microk8s.ctr images ls name~=hello-web
8. sudo docker build . -t localhost:32000/hello-web:latest
9. sudo docker push localhost:32000/hello-web
10. sudo microk8s.kubectl apply -f hello-web-deployment.yaml
11. sudo microk8s.kubectl expose deployment hellow-deployment --type=NodePort --name=hello-service
12. sudo microk8s.kubectl get svc
13. curl http://localhost:<port_no_mentioned_as_output_of_above_command>

### Istio Traces:

1. output-traces/bookinfo/ -> Contains the traces from the sample bookinfo application (Relevant UI pic in pics/bookinfo_jaeger_trace.png)

2. output-traces/sample-page/ -> Contains the traces from the sample-page.py code (Relevant UI pic in pics/sample-page_jaeger_trace.png)

Opentelemetry Traces:

output-traces/opentelemetry/ -> Contains the opentelemetry traces from samples/opentelemetry-code/sample.cc and samples/opentelemetry-code/simple-page.py