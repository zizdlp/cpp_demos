TARGET ?= leetcode155

debug:
	bazel run //coding:coding
demo:
	bazel run //coding:demo

leetcode:
	bazel run //leetcode:$(TARGET)

.PHONY: debug demo leetcode


