#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/JITSymbol.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"

void executeJIT() {
    llvm::LLVMContext Context;
    llvm::Module* M = new llvm::Module("JIT_Module", Context);
    llvm::ExecutionEngine* EE = llvm::EngineBuilder(std::unique_ptr<llvm::Module>(M)).create();

    // Compile HeavyComputation on-the-fly
    llvm::Function* func = M->getFunction("HeavyComputation");
    void* funcPtr = EE->getPointerToFunction(func);

    // Execute the JIT-compiled function
    auto JITFunc = (void(*)())funcPtr;
    JITFunc();
}
