
namespace cpp test

struct Operand{
	1:i32 num
}

service trans_operands{
	void trans_operands(1:Operand first, 2:Operand second)
}

