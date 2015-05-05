import random
NUM_ITEMS = 10007
DATA_FILE_NAME = 'DATA'


def rangeinset(rng, value, s):
    inSet = False
    for i in range(rng):
        if (value + i) in s.keys():
            inSet = True
            break
    return inSet


def randoms(percent_same=0, r=1, num_items=NUM_ITEMS, max_key=65535):
    values = {}
    num_repeat = int(num_items * (percent_same/100))
    for i in range(num_items - num_repeat):
        val = random.randint(0, max_key)
        while rangeinset(r, val, values):
            val = random.randint(0, max_key)
        values[val] = random.randint(0, max_key)
        yield val, values[val]
    j = 0
    for key in values.keys():
        yield key, random.randint(0, max_key)
        if j >= num_repeat:
            break
        j += 1


def main():
    random.seed()

    print('NO_COLLISION')
    f = open(DATA_FILE_NAME+'_NO_COLLISION.txt', 'w')
    f.write(str(NUM_ITEMS+1) + '\n')
    f.write('INSERT %i\n' % NUM_ITEMS)
    for key, val in randoms():
        f.write('%i %i\n' % (key, val))
    f.close()

    print('25')
    f = open(DATA_FILE_NAME+'_25.txt', 'w')
    f.write(str(NUM_ITEMS+1) + '\n')
    f.write('INSERT %i\n' % NUM_ITEMS)
    for key, val in randoms(25):
        f.write('%i %i\n' % (key, val))
    f.close()

    print('50')
    f = open(DATA_FILE_NAME+'_50.txt', 'w')
    f.write(str(NUM_ITEMS+1) + '\n')
    f.write('INSERT %i\n' % NUM_ITEMS)
    for key, val in randoms(50):
        f.write('%i %i\n' % (key, val))
    f.close()

    print('SPARSE')
    f = open(DATA_FILE_NAME+'_SPARSE.txt', 'w')
    f.write(str(NUM_ITEMS+1) + '\n')
    f.write('INSERT %i\n' % NUM_ITEMS)
    for key, val in randoms(percent_same=0, r=5):
        f.write('%i %i\n' % (key, val))
    f.close()

main()
