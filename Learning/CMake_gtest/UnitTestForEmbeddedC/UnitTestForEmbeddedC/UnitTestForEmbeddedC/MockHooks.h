#ifndef __MOCK_HOOKS_H__
#define __MOCK_HOOKS_H__

#if defined(__cplusplus)

#define MOCK_HOOK_RETURN_HANDLING(f_call) \
{ \
	if (EmbeddedCUnitTest::TestFixture::GetMock<MOCK_CLASS>().ShouldReturnAfterHookCall()) { \
		return f_call; \
	} else { \
		f_call; \
	} \
}

#define MOCK_HOOK_P0(f) MOCK_HOOK_RETURN_HANDLING(EmbeddedCUnitTest::TestFixture::GetMock<MOCK_CLASS>().##f())
#define MOCK_HOOK_P1(f, p1) MOCK_HOOK_RETURN_HANDLING(EmbeddedCUnitTest::TestFixture::GetMock<MOCK_CLASS>().##f(p1))
#define MOCK_HOOK_P2(f, p1, p2) MOCK_HOOK_RETURN_HANDLING(EmbeddedCUnitTest::TestFixture::GetMock<MOCK_CLASS>().##f(p1, p2))
#define MOCK_HOOK_P3(f, p1, p2, p3) MOCK_HOOK_RETURN_HANDLING(EmbeddedCUnitTest::TestFixture::GetMock<MOCK_CLASS>().##f(p1, p2, p3))
#define MOCK_HOOK_P4(f, p1, p2, p3, p4) MOCK_HOOK_RETURN_HANDLING(EmbeddedCUnitTest::TestFixture::GetMock<MOCK_CLASS>().##f(p1, p2, p3, p4))
#define MOCK_HOOK_P5(f, p1, p2, p3, p4, p5) MOCK_HOOK_RETURN_HANDLING(EmbeddedCUnitTest::TestFixture::GetMock<MOCK_CLASS>().##f(p1, p2, p3, p4, p5))
#define MOCK_HOOK_P6(f, p1, p2, p3, p4, p5, p6) MOCK_HOOK_RETURN_HANDLING(EmbeddedCUnitTest::TestFixture::GetMock<MOCK_CLASS>().##f(p1, p2, p3, p4, p5, p6))
#define MOCK_HOOK_P7(f, p1, p2, p3, p4, p5, p6, p7) MOCK_HOOK_RETURN_HANDLING(EmbeddedCUnitTest::TestFixture::GetMock<MOCK_CLASS>().##f(p1, p2, p3, p4, p5, p6, p7))
#define MOCK_HOOK_P8(f, p1, p2, p3, p4, p5, p6, p7, p8) MOCK_HOOK_RETURN_HANDLING(EmbeddedCUnitTest::TestFixture::GetMock<MOCK_CLASS>().##f(p1, p2, p3, p4, p5, p6, p7, p8))
#define MOCK_HOOK_P9(f, p1, p2, p3, p4, p5, p6, p7, p8, p9) MOCK_HOOK_RETURN_HANDLING(EmbeddedCUnitTest::TestFixture::GetMock<MOCK_CLASS>().##f(p1, p2, p3, p4, p5, p6, p7, p8, p9))

#else

#define MOCK_HOOK_P0(f)
#define MOCK_HOOK_P1(f, p1)
#define MOCK_HOOK_P2(f, p1, p2)
#define MOCK_HOOK_P3(f, p1, p2, p3)
#define MOCK_HOOK_P4(f, p1, p2, p3, p4)
#define MOCK_HOOK_P5(f, p1, p2, p3, p4, p5)
#define MOCK_HOOK_P6(f, p1, p2, p3, p4, p5, p6)
#define MOCK_HOOK_P7(f, p1, p2, p3, p4, p5, p6, p7)
#define MOCK_HOOK_P8(f, p1, p2, p3, p4, p5, p6, p7, p8)
#define MOCK_HOOK_P9(f, p1, p2, p3, p4, p5, p6, p7, p8, p9)

#endif

#endif /*__MOCK_HOOKS_H__*/
