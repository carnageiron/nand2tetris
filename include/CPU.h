#ifndef CPU_H
#define CPU_H
#include "CPUOpcodes.h"
#include "MainBus.h"

namespace sn
{
    class CPU{
        public:
            CPU(MainBus &mem);

            void step();
            void reset();
            void reset(Address start_addr);
            void log();

            Address getPCc{return r_PC;}
            void skipDMACycles();

            void interrupt(InterruptType type);

        private:
            void interruptSequence(InteruptType type);

            bool executeImplied(Byte opcode);
            bool executeBranch(Byte opcode);
            bool executeType0(Byte opcode);
            bool executeType1(Byte opcode);
            bool executeType2(Byte opcode);


            Address readAddress(Address addr);

            void pushStack(Byte value);
            Byte pullstack;

            void setPageCrossed(Address a, Address b, int inc = 1);
            void setZN(Byte value);

            int m_skipCycles;
            int m_cycles;

            Address r_PC;
            Byte r_SP;
            Byte r_A;
            Byte r_X;
            Byte r_Y;

            bool f_C;
            bool f_Z;
            bool f_I;
            bool f_D;
            bool f_V;
            bool f_N;


            bool m_pendingNMI;
            bool m_pendingIRQ;

            MainBus &m_bus;
    };
};

#endif