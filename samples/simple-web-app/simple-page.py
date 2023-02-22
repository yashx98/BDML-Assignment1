import socketserver
from http.server import BaseHTTPRequestHandler
from opentelemetry import trace

tracer = trace.get_tracer(__name__)

def some_function():
  print("some_function got called")

class MyHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        if self.path == '/captureImage':
            # Insert your code here
            some_function()

        with tracer.start_as_current_span("sample_page_span") as rollspan:
          self.send_response(200)
          self.send_header("Content-type", "text/html")
          self.end_headers()
          self.wfile.write(bytes("<html><head><title>Example web page</title></head>", "utf-8"))
          self.wfile.write(bytes("<body>", "utf-8"))
          self.wfile.write(bytes("<p>This is an example web server.</p>", "utf-8"))
          self.wfile.write(bytes("</body></html>", "utf-8"))
          self.send_response(200)
          rollspan.set_attribute("success", 200)

httpd = socketserver.TCPServer(("", 9090), MyHandler)
httpd.serve_forever()