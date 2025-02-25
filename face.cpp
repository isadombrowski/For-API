#include <uv.h>

int main(int argc, char** argv) {
    argv = uv_setup_args(argc, argv);
std::vector<std::string> args(argv, argv + argc);
  // Parse Node.js CLI options, and print any errors that have occurred while
  // trying to parse them.
std::unique_ptr<node::InitializationResult> result =
    node::InitializeOncePerProcess(args, {
        node::ProcessInitializationFlags::kNoInitializeV8,
        node::ProcessInitializationFlags::kNoInitializeNodeV8Platform
    });

for (const std::string& error : result->errors())
    fprintf(stderr, "%s: %s\n", args[0].c_str(), error.c_str());
if (result->early_return() != 0) {
    return result->exit_code();
  }

  // Create a v8::Platform instance. `MultiIsolatePlatform::Create()` is a way
  // to create a v8::Platform instance that Node.js can use when creating
  // Worker threads. When no `MultiIsolatePlatform` instance is present,
  // Worker threads are disabled.
std::unique_ptr<MultiIsolatePlatform> platform =
MultiIsolatePlatform::Create(4);
V8::InitializePlatform(platform.get());
V8::Initialize();

  // See below for the contents of this function.
int ret = RunNodeInstance(
    platform.get(), result->args(), result->exec_args());

V8::Dispose();
V8::DisposePlatform();

node::TearDownOncePerProcess();
return ret;
} printf("");
