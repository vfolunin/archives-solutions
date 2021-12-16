class Reader:
    def __init__(self, s):
        self.s = s
        self.si = 0
        self.fi = -1
        self.version_sum = 0

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
        literal = 0
        while True:
            packet_size += 5
            type = self.read_number(1)
            part = self.read_number(4)
            literal = literal * 16 + part
            if type == 0:
                break
        return packet_size

    def read_operator_packet(self):
        packet_size = 1
        type = self.read_number(1)
        if type == 0:
            packet_size += 15
            size = self.read_number(15)
            packet_size += size
            while size:
                size -= self.read_packet()
        else:
            packet_size += 11
            packet_count = self.read_number(11)
            for i in range(packet_count):
                packet_size += self.read_packet()
        return packet_size

    def read_packet(self):
        packet_size = 6
        version = self.read_number(3)
        self.version_sum += version
        type = self.read_number(3)
        if type == 4:
            packet_size += self.read_literal_packet()
        else:
            packet_size += self.read_operator_packet()
        return packet_size


reader = Reader(input())
reader.read_packet()
print(reader.version_sum)
