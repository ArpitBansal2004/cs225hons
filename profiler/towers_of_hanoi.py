
def display_towers(towers):
    for i, tower in enumerate(towers):
        print(f"Tower {i + 1}: {tower}")


def initialize_towers(num_discs):
    tower_1 = list(range(num_discs, 0, -1))
    tower_2 = []
    tower_3 = []
    return [tower_1, tower_2, tower_3]


def move_disc(towers, source, destination):
    if not towers[source]:
        return
    disc = towers[source].pop()
    towers[destination].append(disc)


def hanoi_recursive(num_discs, source, auxiliary, destination, towers):
    if num_discs == 1:
        move_disc(towers, source, destination)
        display_towers(towers)
    else:
        hanoi_recursive(num_discs - 1, source, destination, auxiliary, towers)
        move_disc(towers, source, destination)
        display_towers(towers)
        hanoi_recursive(num_discs - 1, auxiliary, source, destination, towers)


def solve_hanoi(num_discs):
    towers = initialize_towers(num_discs)
    display_towers(towers)
    hanoi_recursive(num_discs, 0, 1, 2, towers)

if __name__ == "__main__":
    num_discs = 20
    solve_hanoi(num_discs)