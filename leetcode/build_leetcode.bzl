load("@rules_cc//cc:defs.bzl", "cc_binary","cc_library")

def generate_leetcode_targets(target_names):
    targets = []
    for target_name in target_names: 
        target = cc_binary(
            name = target_name,
            srcs = [target_name + ".cc"],
            copts = [
                "-std=c++17",
                "-g",
            ],
        )
        targets += [target]
    return targets
