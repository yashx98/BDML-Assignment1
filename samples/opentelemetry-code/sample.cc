
#include "opentelemetry/ext/http/client/http_client_factory.h"
#include "opentelemetry/ext/http/common/url_parser.h"
#include "opentelemetry/trace/semantic_conventions.h"
#include "tracer_common.h"
#include "opentelemetry/sdk/trace/tracer_provider_factory.h"

#include <cstdlib.h>

namespace
{

using namespace opentelemetry::trace;
namespace http_client = opentelemetry::ext::http::client;
namespace context     = opentelemetry::context;
namespace nostd       = opentelemetry::nostd;

void experiment() {
  auto exporter = opentelemetry::exporter::trace::OStreamSpanExporterFactory::Create();
  auto processor = opentelemetry::sdk::trace::SimpleSpanProcessorFactory::Create(std::move(exporter));
  std::shared_ptr<opentelemetry::trace::TracerProvider> provider = opentelemetry::sdk::trace::TracerProviderFactory::Create(std::move(processor));
  opentelemetry::trace::Provider::SetTracerProvider(provider);
  auto provider2 = opentelemetry::trace::Provider::GetTracerProvider();
  auto tracer = provider2->GetTracer("ExperiTracer 1");
  auto span = tracer->StartSpan("ExpSpan 1");
  auto scope = tracer->WithActiveSpan(span);
  int i = 0;
  long j = rand() % 10000000000;
  while(i < 1000000000) {
    i++;
  }
  span->End();
}

}  // namespace

int main(int argc, char *argv[])
{
  experiment();
}
