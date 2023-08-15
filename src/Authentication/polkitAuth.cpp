#include "polkitAuth.hpp"

#include <iostream>
#include <polkit/polkit.h>

bool polkitAuth::IsAuthenticated() {
	GError* error = NULL;

	g_setenv("POLKIT_AGENT_LAUNCHER", "/usr/lib/policykit-1-gnome/polkit-gnome-authentication-agent-1:/usr/libexec/polkit-kde-authentication-agent-1:/usr/bin/pkttyagent", TRUE);

	PolkitAuthorizationResult* r = polkit_authority_check_authorization_sync(
		polkit_authority_get_sync(NULL, &error),
		polkit_unix_process_new_for_owner(getpid(), 0, getuid()),
		"org.freedesktop.policykit.exec",
		NULL, /* details */
		POLKIT_CHECK_AUTHORIZATION_FLAGS_ALLOW_USER_INTERACTION,
		NULL, /* cancellable */
		&error
	);

	if (error != NULL) {
		std::cout << "Error: " << error->message << std::endl;
		g_error_free(error);
		return false;
	}

	return polkit_authorization_result_get_is_authorized(r);
}

bool polkitAuth::Authenticate() {
	// GError* error = NULL;

	// PolkitAuthority* authority = polkit_authority_get_sync(NULL, &error);
	// if (error != NULL) {
	// 	std::cout << "Auth Error: " << error->message << std::endl;
	// 	g_error_free(error);
	// 	return false;
	// }

	// PolkitSubject* subject = polkit_unix_process_new_for_owner(getpid(), 0, getuid());
	// if (subject == NULL) {
	// 	std::cout << "Auth Error: Failed to create polkit subject" << std::endl;
	// 	g_object_unref(authority);
	// 	return false;
	// }

	// auto flags = POLKIT_AUTHENTICATION_AGENT_REGISTRATION_FLAGS_NONE;
	// PolkitAuthenticationAgent* agent = polkit_authentication_agent_register_with_options(
	// 	authority,
	// 	"/org/freedesktop/PolicyKit1/AuthenticationAgent",
	// 	flags,
	// 	subject,
	// 	NULL, /* identities */
	// 	NULL, /* details */
	// 	NULL, /* cancellable */
	// 	&error
	// );

	// if (error != NULL) {
	// 	std::cout << "Error: " << error->message << std::endl;
	// 	g_object_unref(subject);
	// 	g_object_unref(authority);
	// 	return false;
	// }

	// polkit_authentication_agent_begin_authentication(agent, "org.freedesktop.policykit.exec", NULL, NULL, NULL, NULL, &error);
	// if (error != NULL) {
	// 	std::cout << "Auth Error: " << error->message << std::endl;
	// 	g_object_unref(agent);
	// 	g_object_unref(subject);
	// 	g_object_unref(authority);
	// 	return false;
	// }

	// polkit_authentication_agent_response(agent, POLKIT_RESPONSE_TYPE_AUTHENTICATION_CANCELLED, NULL, &error);
	// if (error != NULL) {
	// 	std::cout << "Auth Error: " << error->message << std::endl;
	// 	g_object_unref(agent);
	// 	g_object_unref(subject);
	// 	g_object_unref(authority);
	// 	return false;
	// }

	// g_object_unref(agent);
	// g_object_unref(subject);
	// g_object_unref(authority);

	return this->IsAuthenticated();
}
