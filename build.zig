const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const test_module = b.createModule(.{
        .target = target,
        .optimize = optimize,
        .link_libc = true,
    });

    test_module.addIncludePath(b.path("src"));
    test_module.addIncludePath(b.path("include"));

    test_module.addCSourceFiles(.{
        .files = &.{
            "src/test.c",
            "src/array.c",
        },
        .flags = &.{ "-std=c99", "-g", "-Wall", "-Wextra", "-Wpedantic", "-Werror" },
    });

    const lib_module = b.createModule(.{
        .target = target,
        .optimize = optimize,
        .link_libc = true,
    });

    lib_module.addIncludePath(b.path("src"));
    lib_module.addIncludePath(b.path("include"));

    lib_module.addCSourceFiles(.{
        .files = &.{
            "src/array.c",
        },
        .flags = &.{ "-std=c99", "-g", "-Wall", "-Wextra", "-Wpedantic", "-Werror" },
    });

    const lib = b.addLibrary(.{
        .name = "copper",
        .linkage = .static,
        .root_module = lib_module,
    });

    const exe = b.addExecutable(.{
        .name = "test",
        .root_module = test_module,
    });

    b.installArtifact(lib);
    b.installArtifact(exe);

    const test_cmd = b.addRunArtifact(exe);
    test_cmd.step.dependOn(b.getInstallStep());

    const test_step = b.step("test", "Test the library");
    test_step.dependOn(&test_cmd.step);
}
