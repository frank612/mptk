/******************************************************************************/
/*                                                                            */
/*                            test_messaging.cpp                              */
/*                                                                            */
/*                      Matching Pursuit Testing Suite                        */
/*                                                                            */
/* R�mi Gribonval                                                             */
/* Sacha Krstulovic                                           Mon Feb 21 2005 */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/*  Copyright (C) 2005 IRISA                                                  */
/*                                                                            */
/*  This program is free software; you can redistribute it and/or             */
/*  modify it under the terms of the GNU General Public License               */
/*  as published by the Free Software Foundation; either version 2            */
/*  of the License, or (at your option) any later version.                    */
/*                                                                            */
/*  This program is distributed in the hope that it will be useful,           */
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of            */
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             */
/*  GNU General Public License for more details.                              */
/*                                                                            */
/*  You should have received a copy of the GNU General Public License         */
/*  along with this program; if not, write to the Free Software               */
/*  Foundation, Inc., 59 Temple Place - Suite 330,                            */
/*  Boston, MA  02111-1307, USA.                                              */
/*                                                                            */
/******************************************************************************/
/*
 * SVN log:
 *
 * $Author: sacha $
 * $Date: 2006-01-04 19:18:23 +0100 (Wed, 04 Jan 2006) $
 * $Revision: 197 $
 *
 */

#include <mptk.h>

int main( void ) {
	FILE *fid;
	const char* func = "test_messaging";

	mp_info_msg( func, "---------------------------------------------\n" );
	mp_info_msg( func, "TEST - TESTING MPTK MESSAGING FUNCTIONALITIES\n" );
	mp_info_msg( func, "---------------------------------------------\n" );
	mp_error_msg( "foo()", "Bluk bluk: int [%d] str:[%s]\n", 16, "TOTO" );
	mp_warning_msg( "foo()", "Bluk bluk: int [%d] str:[%s]\n", 16, "TOTO" );
	mp_info_msg( "foo()", "Bluk bluk: int [%d] str:[%s] lu:[%lu]\n", 16, "TOTO", 64800 );

	fprintf( stderr, "Should ignore the next DEBUG msg...\n" ); fflush( stderr );
	mp_debug_msg( MP_DEBUG, "foo()", "Bluk bluk: int [%d] str:[%s]\n", 16, "TOTO" );

	fprintf( stderr, "Changing the DEBUG handler...\n" ); fflush( stderr );
	set_debug_handler( MP_FLUSH );
	mp_debug_msg( MP_DEBUG, "foo()", "Bluk bluk: int [%d] str:[%s]\n", 16, "TOTO" );

	fprintf( stderr, "Changing all handlers to IGNORE...\n" ); fflush( stderr );
	set_msg_handler( MP_IGNORE );
	mp_error_msg( "foo()", "Bluk bluk: int [%d] str:[%s]\n", 16, "TOTO" );
	mp_warning_msg( "foo()", "Bluk bluk: int [%d] str:[%s]\n", 16, "TOTO" );
	mp_info_msg( "foo()", "Bluk bluk: int [%d] str:[%s] lu:[%lu]\n", 16, "TOTO", 64800 );
	mp_debug_msg( MP_DEBUG, "foo()", "Bluk bluk: int [%d] str:[%s]\n", 16, "TOTO" );
	fprintf( stderr, "Changing back to FLUSH...\n" ); fflush( stderr );
	set_msg_handler( MP_FLUSH );
	mp_error_msg( "foo()", "Bluk bluk: int [%d] str:[%s]\n", 16, "TOTO" );
	mp_warning_msg( "foo()", "Bluk bluk: int [%d] str:[%s]\n", 16, "TOTO" );
	mp_info_msg( "foo()", "Bluk bluk: int [%d] str:[%s] lu:[%lu]\n", 16, "TOTO", 64800 );
	mp_debug_msg( MP_DEBUG, "foo()", "Bluk bluk: int [%d] str:[%s]\n", 16, "TOTO" );
  
	fprintf( stderr, "Redirecting only warnings to file [test_messaging_warn.out]...\n" ); fflush( stderr );
	fid = fopen( "test_messaging_warn.out", "w" );
	set_msg_stream( stderr );
	set_warning_stream( fid );
	MP_Msg_Server_c::get_msg_server()->register_display_function("warning_message_display",&MP_Msg_Server_c::default_display_in_file_warning_function);
	mp_error_msg( "foo()", "Bluk bluk: int [%d] str:[%s]\n", 16, "TOTO" );
	mp_warning_msg( "foo()", "Bluk bluk: int [%d] str:[%s]\n", 16, "TOTO" );
	mp_info_msg( "foo()", "Bluk bluk: int [%d] str:[%s] lu:[%lu]\n", 16, "TOTO", 64800 );
	mp_debug_msg( MP_DEBUG, "foo()", "Bluk bluk: int [%d] str:[%s]\n", 16, "TOTO" );
	fclose( fid );
	fprintf( stderr, "Done.\n" ); fflush( stderr );
  
	fprintf( stderr, "Redirecting to file [test_messaging.out]...\n" ); fflush( stderr );
	fid = fopen( "test_messaging.out", "w" );
	set_msg_stream( fid );
	set_debug_stream( fid );
	MP_Msg_Server_c::get_msg_server()->register_display_function("info_message_display",&MP_Msg_Server_c::default_display_in_file_info_function);
	MP_Msg_Server_c::get_msg_server()->register_display_function("error_message_display",&MP_Msg_Server_c::default_display_in_file_error_function);
	MP_Msg_Server_c::get_msg_server()->register_display_function("progress_message_display",&MP_Msg_Server_c::default_display_in_file_progress_function);
	MP_Msg_Server_c::get_msg_server()->register_display_function("debug_message_display",&MP_Msg_Server_c::default_display_in_file_debug_function);
	mp_error_msg( "foo()", "Bluk bluk: int [%d] str:[%s]\n", 16, "TOTO" );
	mp_warning_msg( "foo()", "Bluk bluk: int [%d] str:[%s]\n", 16, "TOTO" );
	mp_info_msg( "foo()", "Bluk bluk: int [%d] str:[%s] lu:[%lu]\n", 16, "TOTO", 64800 );
	mp_debug_msg( MP_DEBUG, "foo()", "Bluk bluk: int [%d] str:[%s]\n", 16, "TOTO" );
	fclose( fid );
	fprintf( stderr, "Done.\n" ); fflush( stderr );

	fprintf( stderr, "\nTesting the DEBUG masking system...\n" ); fflush( stderr );

	set_debug_handler( MP_FLUSH );

	fprintf( stderr, "No mask...\n" ); fflush( stderr );
	mp_debug_msg( MP_DEBUG_FUNC_ENTER, "foo()", "Enter\n" );  
	mp_debug_msg( MP_DEBUG, "foo()", "TOTO\n" );  
	mp_debug_msg( MP_DEBUG_FUNC_EXIT, "foo()", "Exit\n" );  

	fprintf( stderr, "Enter only...\n" ); fflush( stderr );
	set_debug_mask( MP_DEBUG_FUNC_ENTER );
	mp_debug_msg( MP_DEBUG_FUNC_ENTER, "foo()", "Enter\n" );  
	mp_debug_msg( MP_DEBUG, "foo()", "TOTO\n" );  
	mp_debug_msg( MP_DEBUG_FUNC_EXIT, "foo()", "Exit\n" );  

	fprintf( stderr, "Enter and exit only...\n" ); fflush( stderr );
	set_debug_mask( MP_DEBUG_FUNC_ENTER | MP_DEBUG_FUNC_EXIT );
	mp_debug_msg( MP_DEBUG_FUNC_ENTER, "foo()", "Enter\n" );  
	mp_debug_msg( MP_DEBUG, "foo()", "TOTO\n" );  
	mp_debug_msg( MP_DEBUG_FUNC_EXIT, "foo()", "Exit\n" );  

	fprintf( stderr, "All again...\n" ); fflush( stderr );
	set_debug_mask( MP_DEBUG_ALL );
	mp_debug_msg( MP_DEBUG_FUNC_ENTER, "foo()", "Enter\n" );  
	mp_debug_msg( MP_DEBUG, "foo()", "TOTO\n" );  
	mp_debug_msg( MP_DEBUG_FUNC_EXIT, "foo()", "Exit\n" );  


	fprintf( stderr, "\nPlain test of the bypass to stderr...\n" ); fflush( stderr );
	mp_info_msg( stderr, "foo()", "BYPASS: int [%d] str:[%s] lu:[%lu]\n", 16, "TOTO", 64800 );

	/* Release Mptk environnement */
	MPTK_Env_c::get_env()->release_environment();

	return( 0 );
}
