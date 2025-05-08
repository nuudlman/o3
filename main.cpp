
#include "fmt/base.h"
#include "fmt/printf.h"
#define VL_PRINTF fmt::printf
#define VL_VPRINTF fmt::vprintf
// #define VL_SNPRINTF fmt::snprintf
#include "verilated.h"

#include <memory>

#include "Vtop.h"

static_assert(VERILATOR_VERSION_INTEGER >= 5034000); // require verilator 5.034 or newer

int main(int argc, char **argv)
{
    fmt::println("Starting sim");

    auto const ctx = std::make_unique<VerilatedContext>();
    ctx->commandArgs(argc, argv);

    auto const top = std::make_unique<Vtop>(ctx.get());

    while (!ctx->gotFinish())
        top->eval();

    fmt::println("Finished sim");
    top->final();

    return 0;
}