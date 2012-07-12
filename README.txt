Commerce Payout is a system that integrates closely with Drupal Commerce to
automate the creation of payments to third parties upon the completion of the
Commerce order. The Rules system is used to provide an easy way to remove
commissions and marketplace fees from these payouts which are grouped by pay
date. Payouts are themselves commerce orders with line items that refer back
to the original purchase line items that generated the payout and the
commerce price component system is used to make the process that created
the payout more easily view-able and transparent.

To set up this module you would
1. Install the module.
2. Set up a rule to create payouts under whatever conditions you desire using
the provided rule action or the api.
3. Setup payout pricing rules to modify the pricing of your payout as you
desire.

At this point there are no payment processors built into commerce to pay the
payouts so you would need to manually pay these and park them as paid
through the admin ui.
