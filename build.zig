const std = @import("std");

pub fn build(b: *std.Build) void {

    const srcs = &.{
        "main.c",
        "ga.c",
        "trade_route.c",
        "utils.c"
    };

    const exe = b.addExecutable(.{
        .name = "red_merchant",
        .link_libc = true,
        .target = b.host,
    });

    exe.addCSourceFiles(.{
        .files = srcs,
        .flags = &.{
            "-Wall",
            "-pedantic"
        }

    });

    b.installArtifact(exe);

    const run_exe = b.addRunArtifact(exe);

    const run_step = b.step("run", "Run the application");
    run_step.dependOn(&run_exe.step);


}
