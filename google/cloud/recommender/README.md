# Recommender C++ Client Library

:construction:

This directory contains an idiomatic C++ client library for
[Recommender][cloud-service], a service on Google Cloud that provides
usage recommendations and insights for Cloud products and services.

This library is **experimental**. Its APIs are subject to change without notice.

Please note that the Google Cloud C++ client libraries do **not** follow
[Semantic Versioning](https://semver.org/).

## Supported Platforms

* Windows, macOS, Linux
* C++11 (and higher) compilers (we test with GCC >= 5.4, Clang >= 6.0, and
  MSVC >= 2017)
* Environments with or without exceptions
* Bazel and CMake builds

## Documentation

* Official documentation about the [Recommender][cloud-service-docs] service
* [Reference doxygen documentation][doxygen-link] for each release of this
  client library
* Detailed header comments in our [public `.h`][source-link] files

[cloud-service]: https://cloud.google.com/recommender
[cloud-service-docs]: https://cloud.google.com/recommender/docs
[doxygen-link]: https://googleapis.dev/cpp/google-cloud-recommender/latest/
[source-link]: https://github.com/googleapis/google-cloud-cpp/tree/main/google/cloud/recommender

## Quickstart

The [quickstart/](quickstart/README.md) directory contains a minimal environment
to get started using this client library in a larger project. The following
"Hello World" program is used in this quickstart, and should give you a taste of
this library.

<!-- inject-quickstart-start -->
```cc
#include "google/cloud/recommender/recommender_client.h"
#include <iostream>
#include <stdexcept>

int main(int argc, char* argv[]) try {
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0]
              << " project-id location-id recommender-id\n";
    return 1;
  }
  // This quickstart does not attempt to validate the Recommender ID. The full
  // list of Recommender IDs can be found here:
  //
  //     https://cloud.google.com/recommender/docs/recommenders#recommenders

  namespace recommender = ::google::cloud::recommender;
  auto client =
      recommender::RecommenderClient(recommender::MakeRecommenderConnection());

  auto const parent = std::string("projects/") + argv[1] + "/locations/" +
                      argv[2] + "/recommenders/" + argv[3];
  for (auto r : client.ListRecommendations(parent)) {
    if (!r) throw std::runtime_error(r.status().message());
    std::cout << r->DebugString() << "\n";
  }

  return 0;
} catch (std::exception const& ex) {
  std::cerr << "Standard exception raised: " << ex.what() << "\n";
  return 1;
}
```
<!-- inject-quickstart-end -->

* Packaging maintainers or developers who prefer to install the library in a
  fixed directory (such as `/usr/local` or `/opt`) should consult the
  [packaging guide](/doc/packaging.md).
* Developers wanting to use the libraries as part of a larger CMake or Bazel
  project should consult the [quickstart guides](#quickstart) for the library
  or libraries they want to use.
* Developers wanting to compile the library just to run some of the examples or
  tests should read the current document.
* Contributors and developers to `google-cloud-cpp` should consult the guide to
  [setup a development workstation][howto-setup-dev-workstation].

[howto-setup-dev-workstation]: /doc/contributor/howto-guide-setup-development-workstation.md

## Contributing changes

See [`CONTRIBUTING.md`](../../../CONTRIBUTING.md) for details on how to
contribute to this project, including how to build and test your changes
as well as how to properly format your code.

## Licensing

Apache 2.0; see [`LICENSE`](../../../LICENSE) for details.