TARGET ?= leetcode155

debug:
	bazel run //coding:coding
demo:
	bazel run //coding:demo
leetcode:
	bazel run //leetcode:$(TARGET)
over:
	bazel run //overflow:run

.PHONY: debug demo leetcode


