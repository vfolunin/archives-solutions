def product(a):
    res = 1
    for x in a:
        res *= x
    return res


class Reader:
    def __init__(self, s):
        self.s = s
        self.si = 0
        self.fi = -1

    def read_four(self):
        self.four = int(self.s[self.si], base=16)
        self.si += 1
        self.fi = 3

    def read_bit(self):
        if self.fi == -1:
            self.read_four()
        bit = bool(self.four & (1 << self.fi))
        self.fi -= 1
        return bit

    def read_number(self, bit_count):
        number = 0
        for i in range(bit_count):
            number = number * 2 + self.read_bit()
        return number

    def read_literal_packet(self):
        packet_size = 0
        value = 0
        while True:
            packet_size += 5
            type = self.read_number(1)
            part = self.read_number(4)
            value = value * 16 + part
            if type == 0:
                break
        return value, packet_size

    def read_operator_packet(self):
        packet_size = 1
        args = []
        type = self.read_number(1)
        if type == 0:
            packet_size += 15
            size = self.read_number(15)
            packet_size += size
            while size:
                arg_value, arg_size = self.read_packet()
                args.append(arg_value)
                size -= arg_size
        else:
            packet_size += 11
            packet_count = self.read_number(11)
            for i in range(packet_count):
                arg_value, arg_size = self.read_packet()
                args.append(arg_value)
                packet_size += arg_size
        return args, packet_size

    def read_packet(self):
        packet_size = 6
        version = self.read_number(3)
        type = self.read_number(3)
        if type == 4:
            value, value_size = self.read_literal_packet()
            packet_size += value_size
        else:
            args, args_size = self.read_operator_packet()
            packet_size += args_size
            if type == 0:
                value = sum(args)
            elif type == 1:
                value = product(args)
            elif type == 2:
                value = min(args)
            elif type == 3:
                value = max(args)
            elif type == 5:
                value = int(args[0] > args[1])
            elif type == 6:
                value = int(args[0] < args[1])
            else:
                value = int(args[0] == args[1])
        return value, packet_size


print(Reader(input()).read_packet()[0])
